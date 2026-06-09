#include "Materia.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void printSection(std::string title) {
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
    // =========================================================================
    // 1. TEST DE L'ÉNONCÉ (Le strict minimum obligatoire)
    // =========================================================================
    printSection("1. TEST DE L'ÉNONCÉ");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
    }

    // =========================================================================
    // 2. ROBUSTESSE DES INDEX & INVENTAIRE PLEIN
    // =========================================================================
    printSection("2. TESTS AUX LIMITES (INDEX ET SHADOWING)");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        ICharacter* cloud = new Character("Cloud");

        // Utilisation ou déséquipement sur des slots vides / inexistants
        std::cout << "Action sur slots invalides (Rien ne doit crash ni s'afficher) :" << std::endl;
        cloud->use(0, *cloud);
        cloud->use(-1, *cloud);
        cloud->use(4, *cloud);
        cloud->unequip(2);
        cloud->unequip(10);

        // Remplissage excessif de l'inventaire
        std::cout << "\nRemplissage de l'inventaire (Max 4) :" << std::endl;
        cloud->equip(src->createMateria("ice")); // Slot 0
        cloud->equip(src->createMateria("ice")); // Slot 1
        cloud->equip(src->createMateria("ice")); // Slot 2
        cloud->equip(src->createMateria("ice")); // Slot 3

        // Le 5ème doit être géré pour éviter le leak, l'inventaire étant plein
        AMateria* overFlowMateria = src->createMateria("ice");
        std::cout << "Tentative d'équiper un 5ème objet :" << std::endl;
        cloud->equip(overFlowMateria); 
        // Si ton Character ne delete pas l'objet s'il ne peut pas l'équiper,
        // tu dois le delete ici manuellement pour éviter un leak.
        if (overFlowMateria) {
            delete overFlowMateria;
        }

        delete cloud;
        delete src;
    }

    // =========================================================================
    // 3. GESTION DU SOL (UNEQUIP)
    // =========================================================================
    printSection("3. TEST DE UNEQUIP ET DU SOL");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Cure());
        Character* sora = new Character("Sora");

        sora->equip(src->createMateria("cure")); // Slot 0
        sora->equip(src->createMateria("cure")); // Slot 1

        std::cout << "Sora utilise le Slot 0 avant unequip :" << std::endl;
        sora->use(0, *sora);

        // On unequip le slot 0. La Materia va sur ton "floor" (liste chaînée)
        sora->unequip(0);

        std::cout << "Sora tente d'utiliser le Slot 0 après unequip (Rien ne doit se passer) :" << std::endl;
        sora->use(0, *sora);

        std::cout << "Sora utilise le Slot 1 toujours actif :" << std::endl;
        sora->use(1, *sora);

        // Re-équiper sur le premier slot libre (qui est redevenu le slot 0)
        sora->equip(src->createMateria("cure"));
        std::cout << "Sora utilise le Slot 0 ré-équipé :" << std::endl;
        sora->use(0, *sora);

        // Tout doit être delete proprement sans leak (y compris la Materia au sol)
        delete sora;
        delete src;
    }

    // =========================================================================
    // 4. DEEP COPY : CONSTRUCTEUR DE RECOPIE & ASSIGNATION
    // =========================================================================
    printSection("4. TEST DES COPIES PROFONDES (DEEP COPY)");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        Character* original = new Character("Original");
        original->equip(src->createMateria("ice"));
        original->equip(src->createMateria("cure"));

        // Test du Constructeur de Recopie
        std::cout << "Création de 'cloneCharacter' par recopie d'Original :" << std::endl;
        Character* cloneCharacter = new Character(*original);

        // Test de l'opérateur d'assignation (=)
        std::cout << "Assignation d'Original dans 'assignedCharacter' :" << std::endl;
        Character* assignedCharacter = new Character("Temp");
        assignedCharacter->equip(src->createMateria("cure")); // Devra être détruit lors de l'assignation
        *assignedCharacter = *original;

        // Modification de l'original pour prouver l'indépendance (Deep Copy)
        std::cout << "\nModification de l'Original (unequip slot 0) :" << std::endl;
        original->unequip(0); 

        std::cout << "\nUtilisation des compétences de l'Original (Slot 0 ne fait rien, Slot 1 OK) :" << std::endl;
        original->use(0, *original);
        original->use(1, *original);

        std::cout << "\nUtilisation du Clone (Doit TOUJOURS avoir son Slot 0 intact !) :" << std::endl;
        cloneCharacter->use(0, *original);
        cloneCharacter->use(1, *original);

        std::cout << "\nUtilisation de l'Assigned (Doit TOUJOURS avoir son Slot 0 intact !) :" << std::endl;
        assignedCharacter->use(0, *original);
       assignedCharacter->use(1, *original);

        delete original;
        delete cloneCharacter;
        delete assignedCharacter;
        delete src;
    }

    // =========================================================================
    // 5. LIMITES DE MATERIASOURCE
    // =========================================================================
    printSection("5. TESTS LIMITES DE MATERIASOURCE");
    {
        IMateriaSource* src = new MateriaSource();
        
        // Essayer de créer avant d'apprendre
        AMateria* unknown = src->createMateria("ice");
        if (unknown == NULL)
            std::cout << "OK: Impossible de créer une Materia non apprise." << std::endl;

        // Remplir la source au maximum
        src->learnMateria(new Ice()); // 1
        src->learnMateria(new Cure()); // 2
        src->learnMateria(new Ice()); // 3
        src->learnMateria(new Cure()); // 4
        
        std::cout << "Tentative d'apprendre une 5ème Materia (Doit être delete proprement) :" << std::endl;
        src->learnMateria(new Ice()); // 5 (Trop plein)

        delete src;
    }
    printSection("FIN DES TESTS - VÉRIFIE LES LEAKS AVEC VALGRIND !");
    return 0;
}
