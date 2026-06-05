#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
public:
	Animal(void);
	Animal(Animal const &other);
	Animal &operator=(Animal const &other);
	virtual ~Animal(void);
	
	virtual void	makeSound(void) const;
	std::string	const &getType(void) const;
protected:
	std::string type;
};

#endif
