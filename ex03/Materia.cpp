#include "Materia.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria	&AMateria::operator=(AMateria const &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

AMateria::~AMateria(void)
{
}

std::string const	&AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter& target)	
{
	std::cout << "A default action has been taken" << std::endl;
}

Ice::Ice(void) : AMateria("ice")
{
}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

Ice::~Ice(void)
{
	AMateria::~AMateria();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice*	Ice::clone() const
{
	Ice	*clone;

	clone = new Ice();
	return (clone);
};

Cure::Cure(void) : AMateria("cure")
{
}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

Cure::~Cure(void)
{
	AMateria::~AMateria();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds  *" << std::endl;
}

Cure*	Cure::clone() const
{
	Cure	*clone;

	clone = new Cure();
	return (clone);
};
