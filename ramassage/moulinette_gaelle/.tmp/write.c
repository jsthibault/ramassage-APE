/*
** write.c for cpp_seminar in /home/maxime/rendu/poule_d01/ex00
** 
** Made by Maxime Brunet
** Login   <maxime1.brunet@epitech.eu>
** 
** Started on  Mon Feb 13 10:23:29 2017 Maxime Brunet
** Last update Mon Feb 13 11:44:56 2017 Maxime Brunet
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1,&c,1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;
  int	nbr;

  i = 0;
  nbr = 1;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	nbr++;
      i++;
    }
  return (nbr);
}

int     my_getnbr(char *str)
{
  int   i;
  int   nbr;
  int   n;

  n = 0;
  i = 0;
  if (str[0] == '-')
    {
      nbr = 1;
      i = 1;
    }
  while (str[i] != '\0')
    {
      n = n * 10 + (str[i] - 48);
      i = i + 1;
    }
  if (nbr == 1)
    {
      n = n * -1;
    }
  return(n);
}
