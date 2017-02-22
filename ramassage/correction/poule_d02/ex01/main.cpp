
#include "AChild.hh"
#include "Son.hh"
#include "Daughter.hh"

int		main()
{
  Son*			s1 = new Son("Goku");
  Son*			s2(s1);
  Daughter		d1("Pan");
  Daughter		d2("Tata");
  AChild*		tmp;

  d2 = d1;
  tmp = s2;
  tmp->dump();
  d2.dump();
}
