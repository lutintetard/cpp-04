#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include <iostream>
# include "Materia.hpp"

class IMateriaSource
{
public:
	IMateriaSource();
	IMateriaSource(IMateriaSource const &other);
	IMateriaSource	&operator=(IMateriaSource const &other);
	virtual ~IMateriaSource();
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class	MateriaSource : public IMateriaSource
{
private:
	AMateria	*mat[4];
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &other);
	MateriaSource &operator=(MateriaSource const &other);
	~MateriaSource(void);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif
