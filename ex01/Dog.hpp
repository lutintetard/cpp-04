#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const &other);
	Dog &operator=(Dog const &other);
	~Dog(void);
	void	makeSound(void) const;
	Brain	*getBrain(void) const;
private:
	Brain *brain;
};

#endif
