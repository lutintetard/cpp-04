#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
} 

MateriaSource::MateriaSource(MateriaSource const &other)
{
	int	index;

	std::memset(this->mat, 0, sizeof(AMateria *) * 4);
	index = 0;
	for (int i = 0; i < 4; i++)
	{
		if (other.mat[i] != NULL)
		{
			this->mat[index] = other.mat[i].clone();
			index++;
		}
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		MateriaSource	copy(other);

		this->mat = copy.mat; 
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	//peut etre qu'il faut gerer la memoire ici
}

void	MateriaSource::learnMateria(AMateria *other)
{
	int	index;

	for (int i = 0; i < 4; i++)
	{
		if (other[i] != NULL)
		{
			this->mat[index] = other.clone();
			return ;
		}
	}
	std::cout << "Maximum amount of Materia known" << std::endl;
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i] != NULL && this->mat[i].getType() == type)
		{
			return (new AMateria(type));
		}
	}
	std::cout << "This objet is unknown" << std::endl;
	return (NULL);
}
