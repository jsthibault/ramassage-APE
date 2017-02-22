
#include <iostream>
#include "AChild.hh"

AChild::AChild()
{

}

AChild::~AChild()
{

}

const std::string&	AChild::getName() const
{
  return _name;
}

void			AChild::dump() const
{
  std::cout << "This is " << getName() << " ";
  if (isBoy())
    {
      std::cout << "and it's boy" << std::endl;
    }
  else if (isGirl())
    {
      std::cout << "and it's girl" << std::endl;
    }
}
