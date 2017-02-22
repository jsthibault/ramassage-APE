/**
 **	Workshop c++
 **	Template
 **	Epitech Tech 2
**/

#include <iostream>
#include <typeinfo>
#include "my_class.hpp"

int	main(int ac [[gnu::unused]], char **av [[gnu::unused]])
{
  int	i = 1;
  my_class	<int>my_c(i);
  my_class	<int>my_c2(my_c);
  my_class	<int>my_c3(0);
  my_class	<const char *>my_c4("hello");
  
  my_c3 = my_c2;

  my_c.action();
  my_c4.action();
  return (0);
}
