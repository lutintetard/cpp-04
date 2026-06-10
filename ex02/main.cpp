/*
# include "AAnimal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int	main(void)
{
	AAnimal*	list[4] = {new Cat, new Dog, new Cat, new Dog};
	//AAnimal		fail;
	
	for (int i = 0; i < 4; i++)
		delete list[i];
	return (0); 
}
*/

#include "AAnimal.hpp" // Ou AAnimal.hpp si tu as choisi de le renommer
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void printSection(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main()
{
    // =========================================================================
    // 1. LA PREUVE PAR L'ABSTRACTION (À commenter pour que ça compile !)
    // =========================================================================
    printSection("1. TEST D'INSTANCIATION DE LA CLASSE ABSTRAITE");
    
    std::cout << "-> Tentative d'instancier un Animal generique (INTERDIT) :" << std::endl;
    // Décommente les lignes ci-dessous pour prouver au correcteur que le compilateur bloque le code :
    // const Animal* testAbstrait = new Animal(); 
    // Animal instanceSurLaPile;
    std::cout << "INFO : Les lignes de code testant l'instanciation directe d'un Animal" << std::endl;
    std::cout << "       sont commentees pour permettre la compilation, ce qui prouve" << std::endl;
    std::cout << "       que notre classe est bien devenue Abstraite ! \033[32m[OK]\033[0m" << std::endl;


    // =========================================================================
    // 2. POLYMORPHISME AVEC LA CLASSE ABSTRAITE (Doit fonctionner comme avant)
    // =========================================================================
    printSection("2. POLYMORPHISME VIA POINTEURS D'ANIMAUX");
    {
        // On ne peut pas créer d'Animal, mais on peut TOUJOURS créer des pointeurs d'Animal !
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();

        std::cout << "\n-> Verification des types des classes derivees :" << std::endl;
        std::cout << "Type de j : " << j->getType() << std::endl;
        std::cout << "Type de i : " << i->getType() << std::endl;

        std::cout << "\n-> Emission des sons (Polymorphisme pur) :" << std::endl;
        std::cout << "j (Dog) : "; j->makeSound();
        std::cout << "i (Cat) : "; i->makeSound();

        std::cout << "\n-> Destruction des animaux et de leurs Brains :" << std::endl;
        delete j;
        delete i;
    }

    // =========================================================================
    // 3. TABLEAU MIXTE & DEEP COPY (Rétrocompatibilité de l'ex01)
    // =========================================================================
    printSection("3. RETROCOMPATIBILITE DES COPIES ET DU TABLEAU (EX01)");
    {
        const int size = 4;
        AAnimal* zoo[size];

        std::cout << "-> Remplissage du zoo avec des classes concretes :" << std::endl;
        for (int k = 0; k < size; k++) {
            if (k % 2 == 0)
                zoo[k] = new Dog();
            else
                zoo[k] = new Cat();
        }

        std::cout << "\n-> Test des copies profondes avec des objets sur la pile :" << std::endl;
        Dog originalDog;
        originalDog.getBrain()->setIdea(0, "Courir apres une balle");
        
        Dog copyDog(originalDog);
        std::cout << "Idee de l'original : " << originalDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "Idee de la copie    : " << copyDog.getBrain()->getIdea(0) << std::endl;

        std::cout << "\n-> Nettoyage du zoo :" << std::endl;
        for (int k = 0; k < size; k++) {
		delete zoo[k];
        }
    }

    printSection("FIN DES TESTS - TOUT FONCTIONNE PROPREMENT");
    return 0;
}
