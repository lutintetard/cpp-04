#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

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
	AMateria* clone() const;
	void	use(ICharacter& target);
};

class	Cure : public AMateria
{
public:
	AMateria* clone() const;
	void	use(ICharacter& target);
};

#endif
