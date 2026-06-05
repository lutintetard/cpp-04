# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int	main(void)
{
	Animal	list[4] = {Cat(), Dog(), Cat(), Dog()};
	
	return (0); 
}
