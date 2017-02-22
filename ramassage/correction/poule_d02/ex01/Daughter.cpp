
#include "Daughter.hh"

Daughter::Daughter(const std::string & name)
{
  _name = name;
}

Daughter::Daughter(const Daughter& e)
{
  _name = e._name;
}

Daughter::~Daughter()
{

}

Daughter&		Daughter::operator=(const Daughter &e)
{
  _name = e._name;
  return (*this);
}

bool		Daughter::isBoy() const
{
  return false;
}

bool		Daughter::isGirl() const
{
  return true;
}
