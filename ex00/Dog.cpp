#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "An instance of the class Dog has been created" << std::endl;
}

Dog::Dog(Dog const &other) : Animal()
{
	this->type = other.type;	
}

Dog &Dog::operator=(Dog const &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "An instance of the class Dog has been deleted" << std::endl;	
}

void	Dog::makeSound(void) const
{
	std::cout << "This dog barks" << std::endl;
}
