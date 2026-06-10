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
	void	setIdea(int idx, std::string id);
	std::string	getIdea(int idx) const;
	std::string ideas[100];
};

#endif
