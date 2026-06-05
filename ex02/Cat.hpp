#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Cat : public AAnimal
{
public:
	Cat(void);
	Cat(Cat const &other);
	Cat &operator=(Cat const &other);
	~Cat(void);
	void	makeSound(void) const;
private:
	Brain *brain;
};

#endif
