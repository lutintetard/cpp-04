/*
# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int	main(void)
{
	Animal	hello;
	Animal	bye(hello);
	Animal	*a = new Cat();
	Animal	*b = new Dog();
	WrongAnimal *c = new WrongCat();

	hello = bye;
	hello.makeSound();
	std::cout << "The type of the instance is " << hello.getType() << std::endl;
	a->makeSound();
	std::cout << "The type of the instance is " << a->getType() << std::endl;
	b->makeSound();
	std::cout << "The type of the instance is " << b->getType() << std::endl;
	c->makeSound();
	std::cout << "The type of the instance is " << c->getType() << std::endl;
	delete a;
	delete b;
	return (0); 
}
*/

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void printSection(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main()
{
    // =========================================================================
    // 1. TEST DE L'ÉNONCÉ (Le strict minimum requis)
    // =========================================================================
    printSection("1. TEST DE L'ENONCE (POLYMORPHISME VALIDE)");
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "\n-> Verification des types :" << std::endl;
        std::cout << "Type de j : " << j->getType() << " " << std::endl;
        std::cout << "Type de i : " << i->getType() << " " << std::endl;

        std::cout << "\n-> Cris des animaux (Doit executer les cris specifiques) :" << std::endl;
        std::cout << "i (Cat)  : "; i->makeSound(); // Miaou !
        std::cout << "j (Dog)  : "; j->makeSound(); // Wouf !
        std::cout << "meta     : "; meta->makeSound(); // Son par défaut

        std::cout << "\n-> Destruction des animaux (Regarde bien le chainage) :" << std::endl;
        delete meta;
        delete j; // Si ~Animal() est virtuel, appelle ~Dog() PUIS ~Animal()
        delete i; // Si ~Animal() est virtuel, appelle ~Cat() PUIS ~Animal()
    }

    // =========================================================================
    // 2. LE CAS TRAP : WRONG ANIMAL (POLYMORPHISME BRISÉ)
    // =========================================================================
    printSection("2. TEST DES WRONG CLASSES (POLYMORPHISME BRISE)");
    {
        std::cout << "-> Creation d'un WrongCat cache derriere un pointeur WrongAnimal :" << std::endl;
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << "\n-> Verification du type :" << std::endl;
        std::cout << "Type de wrongCat : " << wrongCat->getType() << std::endl;

        std::cout << "\n-> Cri du WrongCat (Piege : Doit sortir le son du WrongAnimal !) :" << std::endl;
        std::cout << "wrongCat : "; wrongCat->makeSound(); // Print le son générique car pas de 'virtual' !
        std::cout << "wrongMeta: "; wrongMeta->makeSound();

        std::cout << "\n-> Appel direct depuis la classe concrete (Pour prouver que le chat sait miauler) :" << std::endl;
        const WrongCat* directCat = new WrongCat();
        std::cout << "directCat: "; directCat->makeSound(); // Ici, il miaule !

        std::cout << "\n-> Destruction (Attention au leak si le destructeur n'est pas virtuel !) :" << std::endl;
        delete wrongMeta;
        delete wrongCat; // N'appellera PAS ~WrongCat() si le destructeur n'est pas virtuel.
        delete directCat;
    }

    // =========================================================================
    // 3. TESTS SUR LA PILE (STACK ALLOCATION & COPIES)
    // =========================================================================
    printSection("3. ALLOCATION SUR LA PILE ET FORMES CANONIQUES");
    {
        std::cout << "-> Creation directe sur la pile :" << std::endl;
        Dog stackDog;
        Cat stackCat;

        std::cout << "\n-> Cris sur la pile :" << std::endl;
        stackDog.makeSound();
        stackCat.makeSound();

        std::cout << "\n-> Test du constructeur de recopie de Dog :" << std::endl;
        Dog copiéDog(stackDog);
        std::cout << "Type de la copie : " << copiéDog.getType() << std::endl;
        copiéDog.makeSound();

        std::cout << "\n-> Test de l'operateur d'assignation (=) de Cat :" << std::endl;
        Cat assignéCat;
        assignéCat = stackCat;
        std::cout << "Type de l'assigne : " << assignéCat.getType() << std::endl;
        assignéCat.makeSound();

        std::cout << "\n-> Sortie de scope (Destruction automatique sur la pile) :" << std::endl;
    }

    printSection("FIN DES TESTS - LANCE LE SCRIPT AVEC VALGRIND !");
    return 0;
}
