#include "Animal.hpp"

Animal::Animal(void) : type("Undefined")
{
	std::cout << "An instance of the class Animal has been created" << std::endl;
}

Animal::Animal(Animal const &other)
{
	this->type = other.type;	
}

Animal &Animal::operator=(Animal const &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "An instance of the class Animal has been deleted" << std::endl;	
}

void	Animal::makeSound(void) const
{
	std::cout << "This Animal makes an undefined noise" << std::endl;
}

std::string const &Animal::getType(void) const
{
	return (type);
}
