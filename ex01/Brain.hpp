#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
public:
	Brain(void);
	Brain(Brain const &other);
	Brain &operator=(Brain const &other);
	~Brain(void);
	std::string ideas[100];
};

#endif
