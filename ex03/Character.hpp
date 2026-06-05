#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
private:
	std::string name; //a verifier que c'est ici qu'il faut implementer
};

#endif
