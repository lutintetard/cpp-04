#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class ICharacter;
# include "Materia.hpp"
# include <cstring>

class ICharacter
{
public:
	virtual ~ICharacter();
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

typedef struct s_node
{
	AMateria *content;
	struct s_node *next;
} t_node;

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria	*mat[4];
	static t_node	*floor;
	static int		total_floor;
public:
	Character(std::string const &name);
	Character(Character const &other);
	Character &operator=(Character const &other);
	 ~Character();
	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
