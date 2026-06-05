#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Undefined")
{
	std::cout << "An instance of the class AAnimal has been created" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other)
{
	this->type = other.type;	
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "An instance of the class AAnimal has been deleted" << std::endl;	
}

std::string const &AAnimal::getType(void) const
{
	return (type);
}
