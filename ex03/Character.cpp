#include "Character.hpp"

Character::Character(std::string const &name) : name(name)
{
	std::memset(this->mat, 0, sizeof(AMateria *) * 4);
}

Character::Character(Character const &other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.mat[i] != NULL)
		{
			this->mat[i] = other.mat[i]->clone();
		}
		else
			this->mat[i] = NULL;
	}
}

Character	&Character::operator=(Character const &other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (mat[i] != NULL)
			{
				delete mat[i];
				mat[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.mat[i] != NULL)
			{
				mat[i] = other.mat[i]->clone();
			}
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i] != NULL)
			delete mat[i];
	}
}

std::string const	&Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i] == 0)
		{
			mat[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full :(" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || mat == NULL || mat[idx] == NULL)
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	t_node *newNode = new t_node;
	newNode->content =  mat[idx];
	newNode->next =  NULL;
	if (floor == NULL)
		floor = newNode;
	else
	{
		t_node *temp;
		temp = floor;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	mat[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || mat == NULL || this->mat[idx] == NULL)
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	mat[idx]->use(target);
	delete mat[idx];
	mat[idx] = NULL;
}

int	Character::total_floor = 0;
t_node	*Character::floor = NULL;
