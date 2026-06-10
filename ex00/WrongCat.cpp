#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "An instance of the class WrongCat has been created" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal()
{
	this->type = other.type;	
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "An instance of the class WrongCat has been deleted" << std::endl;	
}

void	WrongCat::makeSound(void) const
{
	std::cout << "This cat meows" << std::endl;
}
