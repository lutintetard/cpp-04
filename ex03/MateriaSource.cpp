#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::memset(this->mat, 0, sizeof(AMateria *) * 4);
} 

MateriaSource::MateriaSource(MateriaSource const &other)
{
	std::memset(this->mat, 0, sizeof(AMateria *) * 4);
	for (int i = 0; i < 4; i++)
	{
		if (other.mat[i] != NULL)
		{
			this->mat[i] = other.mat[i]->clone();
		}
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->mat[i] != NULL)
			{
				delete this->mat[i];
				this->mat[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.mat[i] != NULL)
				this->mat[i] = other.mat[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (mat[i] != NULL)
		{
			delete mat[i];
			mat[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i] == NULL)
		{
			this->mat[i] = other;
			return ;
		}
	}
	delete other;
	other = NULL;
	std::cout << "Maximum amount of Materia known" << std::endl;
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i] != NULL && this->mat[i]->getType() == type)
		{
			AMateria	*copy;
			
			if (type == "ice")
				copy = new Ice();
			else if (type == "cure")	
				copy = new Cure(); 
			return (copy);
		}
	}
	std::cout << "This object is unknown" << std::endl;
	return (NULL);
}
