//
// main.cpp for main in /Users/mowgli/Projects/Atelier/atelierConstRef/Good
// 
// Made by Mowgli
// Login   <Mowgli@epitech.net>
// 
// Started on  Fri Jan 13 10:14:57 2017 Mowgli
// Last update Fri Jan 13 10:36:51 2017 Mowgli
//

#include "APE.hh"
#include "iostream"

int		main(__attribute__((unused))int ac, __attribute__((unused)) char **av)
{
  APE const	obj("Hadrien");
  
  std::cout << obj.getName() << std::endl;
  return (1);
}
