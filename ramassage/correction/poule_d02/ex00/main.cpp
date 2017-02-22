
#include <vector>
#include "Element.hh"

int	main()
{
  const Element			e1(1, "First Element");
  Element			copy(e1);
  Element			e2(2, "Second Element");
  std::vector<const Element*>	tab;

  tab.push_back(&e1);
  tab.push_back(&copy);
  tab.push_back(&e2);
  copy = e2;
  for (int i = 0; i != tab.size(); i++)
    tab[i]->show();
}
