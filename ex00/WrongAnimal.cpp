#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Undefined")
{
	std::cout << "An instance of the class WrongAnimal has been created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	this->type = other.type;	
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "An instance of the class WrongAnimal has been deleted" << std::endl;	
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "This WrongAnimal makes an undefined noise" << std::endl;
}

std::string const &WrongAnimal::getType(void) const
{
	return (type);
}
