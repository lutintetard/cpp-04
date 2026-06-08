#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "Character.hpp"

class AMateria
{
protected:
	std::string	type;
public:
	AMateria(std::string const & type);
	AMateria &operator=(AMateria const & other);
	~AMateria(void);
	std::string const & getType() const; 
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

class	Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice &operator=(Ice const &other);
	Ice* clone() const;
	void	use(ICharacter& target);
};

class	Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure &operator=(Cure const &other);
	Cure* clone() const;
	void	use(ICharacter& target);
};

#endif
