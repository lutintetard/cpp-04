/*
# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int	main(void)
{
	Animal	list[4] = {Cat(), Dog(), Cat(), Dog()};
	
	return (0); 
}
*/

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <sstream>

void printSection(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main()
{
    // =========================================================================
    // 1. TEST DE L'ÉNONCÉ (Le strict minimum sans leak)
    // =========================================================================
    printSection("1. TEST DE L'ENONCE BASE");
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << std::endl;
        delete j; // Ne doit pas créer de fuite (le Brain du Dog doit être delete)
        delete i; // Ne doit pas créer de fuite (le Brain du Cat doit être delete)
    }

    // =========================================================================
    // 2. LE TABLEAU MIXTE (Exigence explicite du sujet)
    // =========================================================================
    printSection("2. CREATION ET DESTRUCTION DU TABLEAU D'ANIMAUX");
    {
        const int size = 6; // Tu peux mettre 20 ou 100, gardons 6 pour la lisibilité des logs
        Animal* animals[size];

        std::cout << "-> Remplissage du tableau (Moitie Dog, Moitie Cat) :" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << "[Animal " << i << "]" << std::endl;
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        std::cout << "\n-> Verification des cris des animaux du tableau :" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << "Animal " << i << " (" << animals[i]->getType() << ") : ";
            animals[i]->makeSound();
        }

        std::cout << "\n-> Libération directe en tant qu'Animal* :" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << "[Delete Animal " << i << "]" << std::endl;
            delete animals[i]; // Invoque le destructeur de l'enfant PUIS de l'Animal grâce au virtual !
        }
    }

    // =========================================================================
    // 3. VÉRIFICATION DE LA COPIE PROFONDE (Deep Copy Test)
    // =========================================================================
    printSection("3. TEST DES COPIES PROFONDES (DEEP COPY)");
    {
        std::cout << "-> Initialisation d'un Dog original avec des idées :" << std::endl;
        Dog* originalDog = new Dog();
        
        // Supposons que tu as des fonctions pour manipuler les idées dans ton Dog/Brain
        // (Fortement recommandé pour prouver la deep copy en soutenance !)
        originalDog->getBrain()->setIdea(0, "Attraper le facteur");
        originalDog->getBrain()->setIdea(1, "Manger des croquettes");

        std::cout << "\n-> Test du Constructeur de Recopie (Deep Copy) :" << std::endl;
        Dog* copyDog = new Dog(*originalDog);

        std::cout << "\n-> Test de l'Opérateur d'Assignation (Deep Copy) :" << std::endl;
        Dog* assignedDog = new Dog();
        *assignedDog = *originalDog;

        std::cout << "\n-> Modification des idées de l'Original pour vérifier l'indépendance :" << std::endl;
        originalDog->getBrain()->setIdea(0, "Dormir sur le canapé");

        std::cout << "\n-> Comparaison des adresses des Brains (Elles doivent être DIFFÉRENTES) :" << std::endl;
        std::cout << "Adresse Brain Original : " << originalDog->getBrain() << std::endl;
        std::cout << "Adresse Brain Copie    : " << copyDog->getBrain() << std::endl;
        std::cout << "Adresse Brain Assigné  : " << assignedDog->getBrain() << std::endl;

        std::cout << "\n-> Comparaison du contenu des idées :" << std::endl;
        std::cout << "Original Idée 0 : " << originalDog->getBrain()->getIdea(0) << " (Doit être modifié)" << std::endl;
        std::cout << "Copie    Idée 0 : " << copyDog->getBrain()->getIdea(0) << " (Doit être intacte)" << std::endl;
        std::cout << "Assigné  Idée 0 : " << assignedDog->getBrain()->getIdea(0) << " (Doit être intacte)" << std::endl;

        std::cout << "\n-> Destruction des objets (Aucun Double Free ne doit se produire) :" << std::endl;
        delete originalDog;
        delete copyDog;
        delete assignedDog;
    }

    printSection("FIN DES TESTS");
    return 0;
}
