# include "AAnimal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int	main(void)
{
	AAnimal*	list[4] = {new Cat, new Dog, new Cat, new Dog};
	//AAnimal		fail;
	
	for (int i = 0; i < 4; i++)
		delete list[i];
	return (0); 
}
