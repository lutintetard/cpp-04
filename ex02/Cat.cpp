#include "Cat.hpp"

Cat::Cat(void) : brain(new Brain())
{
	this->type = "Cat";
	std::cout << "An instance of the class Cat has been created" << std::endl;
}

Cat::Cat(Cat const &other)
{
	this->brain = new Brain();
	this->type = other.type;	
}

Cat &Cat::operator=(Cat const &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	delete this->brain;
	this->brain = other.brain;
	return (*this);
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "An instance of the class cat has been deleted" << std::endl;	
}

void	Cat::makeSound(void) const
{
	std::cout << "This cat meows" << std::endl;
}
