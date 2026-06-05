#include "Dog.hpp"

Dog::Dog(void) : brain(new Brain)
{
	this->type = "Dog";
	std::cout << "An instance of the class Dog has been created" << std::endl;
}

Dog::Dog(Dog const &other)
{
	this->brain = new Brain();
	this->type = other.type;
}

Dog &Dog::operator=(Dog const &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	delete this->brain;
	this->brain = new Brain();
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "An instance of the class dog has been deleted" << std::endl;	
}

void	Dog::makeSound(void) const
{
	std::cout << "This dog barks" << std::endl;
}
