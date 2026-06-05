#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
public:
	AAnimal(void);
	AAnimal(AAnimal const &other);
	AAnimal &operator=(AAnimal const &other);
	virtual ~AAnimal(void);
	
	virtual void	makeSound(void) const = 0;
	std::string	const &getType(void) const;
protected:
	std::string type;
};

#endif
