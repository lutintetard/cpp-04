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
