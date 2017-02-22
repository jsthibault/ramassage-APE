
#ifndef _SON_HH_
# define _SON_HH_

#include "AChild.hh"

class	Son : public AChild
{
public:
  Son(const std::string &name);
  Son(const Son&);
  virtual ~Son();
  Son& operator=(const Son&);

  bool		isBoy() const;
  bool		isGirl() const;
};

#endif
