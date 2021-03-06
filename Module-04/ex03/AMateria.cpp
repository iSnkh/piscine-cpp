#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	return ;
}

AMateria::~AMateria()
{
	return ;
}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
}

AMateria	&AMateria::operator=(AMateria const &copy)
{
	this->_type = copy._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}