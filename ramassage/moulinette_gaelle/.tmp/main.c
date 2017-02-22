/*
** main.c for cpp in /home/maxime/rendu/poule_d01/ex00
** 
** Made by Maxime Brunet
** Login   <maxime1.brunet@epitech.eu>
** 
** Started on  Mon Feb 13 10:25:43 2017 Maxime Brunet
** Last update Mon Feb 13 12:09:49 2017 Maxime Brunet
*/

#include "my.h"

int	main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
  char	str[] = "4 8 15 16 23 42";

  int	**tab = str_to_int_tab(str);
  /* print_int_tab(tab); */
  return (0);
}
