
#ifndef	_ACHILD_HH_
# define _ACHILD_HH_

# include <string>

class AChild
{
public:
  AChild();
  ~AChild();

  virtual const std::string&	getName() const;
  virtual void			dump() const;
  virtual bool			isBoy() const = 0;
  virtual bool			isGirl() const = 0;

protected:
  std::string			_name;
};

#endif /* _ACHILD_HH_ */
