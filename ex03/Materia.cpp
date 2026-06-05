#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria	&AMateria::operator=(AMateria const &other) : type(other.type)
{
}

AMateria::~AMateria(void)
{
}

AMateria*	AMateria::clone() const
{
	AMateria	*clone;

	clone = new AMateria(this->type);
	return (clone);
};

void	AMateria::use(ICharacter& target)
{

}
