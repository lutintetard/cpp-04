#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "";
	}
}

Brain::Brain(Brain const &other)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(Brain const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
		return (*this);
	}
	return (*this);
}

Brain::~Brain(void)
{
}

void	Brain::setIdea(int idx, std::string id)
{
	if (idx < 0 || idx > 99)
	{
		std::cout << "The index is not within possible range" << std::endl;
		return ;
	}
	ideas[idx] = id;
}

std::string	Brain::getIdea(int idx) const
{
	if (idx < 0 || idx > 99)
	{
		std::cout << "The index is not within possible range" << std::endl;
		return ("");
	}
	return (ideas[idx]);	
}
