/*
** my_getnbr.c for str_to_int_tab in /home/kougbe_o/work/Piscine/poule_d01
** 
** Made by Oswald Kougbenya
** Login   <kougbe_o@epitech.net>
** 
** Started on  Mon Feb 13 10:24:26 2017 Oswald Kougbenya
** Last update Mon Feb 13 12:37:18 2017 Oswald Kougbenya
*/

#include <unistd.h>
#include <stdlib.h>

#define NB_BY_ROW 3

int		my_getnbr(char **str)
{
  int		result;
  char		neg;

  result = 0;
  neg = 1;
  while (str && str[0] && *str[0] && (*str[0] == '-' || *str[0] == '+'))
    {
      neg = *str[0] == '-' ? -neg : neg;
      str[0] += 1;
    }
  while (str && str[0] && *str[0] && (*str[0] >= '0' || *str[0] <= '9'))
    {
      result = 10 * result + (*str[0] - 48);
      str[0] += 1;
    }
  return (result * neg);
}

int	**str_to_int_array(char *str)
{
  int	**tab;
  int	rows;
  int	cols;

  tab = (void*)0 + (rows = 0);
  while (str && !(cols = 0))
    {
      if ((tab = realloc(tab, sizeof(*tab) * (rows + 2))) == NULL ||
	  (tab[rows] = malloc(sizeof(*tab[rows]) * NB_BY_ROW)) == NULL)
	return (NULL);
      while (str && (cols += 1) < NB_BY_ROW + 1)
	{
	  tab[rows][cols - 1] = my_getnbr(&str);
	  str += *str == ' ' ? 1 : 0;
	}
      rows += 1;
    }
  while (cols += 1 < NB_BY_ROW + 1)
    tab[rows - 1][cols - 1] = 0;
  if ((tab[rows] = malloc(sizeof(*tab[rows]) * NB_BY_ROW)) == NULL)
    return (NULL);
  while (cols -= 1)
    tab[rows][cols] = -1;
  tab[rows + 1] = NULL;
  return (tab);
}
  
