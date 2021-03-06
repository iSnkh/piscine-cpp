#include "DogClass.hpp"

Dog::Dog(void) : Animal(), _type("Dog")
{
	std::cout << "[Animal] Creating Dog using Default Type" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	std::cout << "[Animal] Creating Dog using Copy and " << this->_type << " as Type" << std::endl;
	*this = copy;
}

Dog::~Dog(void)
{
	std::cout << "[Animal] Destructing Dog" << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
	std::cout << "Operator = of Dog" << std::endl;
	this->_type = copy._type;
	return (*this);
}

std::string		Dog::getType(void) const
{
	return (this->_type);
}

void			Dog::makeSound(void) const
{
	std::cout << "[Animal] WOUAF!!!" << std::endl;
}
