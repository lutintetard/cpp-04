#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "An instance of the class Cat has been created" << std::endl;
}

Cat::Cat(Cat const &other) : Animal()
{
	this->type = other.type;
}

Cat &Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "An instance of the class Cat has been deleted" << std::endl;	
}

void	Cat::makeSound(void) const
{
	std::cout << "This cat meows" << std::endl;
}
