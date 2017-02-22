
#include "Son.hh"

Son::Son(const std::string & name)
{
  _name = name;
}

Son::Son(const Son& e)
{
  _name = e._name;
}

Son::~Son()
{

}

Son&		Son::operator=(const Son &e)
{
  _name = e._name;
  return (*this);
}

bool		Son::isBoy() const
{
  return true;
}

bool		Son::isGirl() const
{
  return false;
}
