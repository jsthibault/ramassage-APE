
#ifndef _DAUGHTER_HH_
# define _DAUGHTER_HH_

#include "AChild.hh"

class	Daughter : public AChild
{
public:
  Daughter(const std::string &name);
  Daughter(const Daughter&);
  virtual ~Daughter();
  Daughter& operator=(const Daughter&);

  bool		isBoy() const;
  bool		isGirl() const;
};

#endif
