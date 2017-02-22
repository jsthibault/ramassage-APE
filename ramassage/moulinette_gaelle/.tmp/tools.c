/*
** tools.c for  in /home/bivman/delivery/poule_d01/ex00
** 
** Made by yves adonias
** Login   <bivman@epitech.net>
** 
** Started on  Mon Feb 13 10:48:09 2017 yves adonias
** Last update Mon Feb 13 11:38:29 2017 yves adonias
*/

#include "tools.h"

int			my_atoi(char *str)
{
  int			mult;
  int			i;
  int			result;

  mult = 1;
  i = 0;
  result = 0;
  while (str[i] && get_if_num(str[i]))
    {
      result = result * mult;
      result += (str[i] - 48);
      mult *= 10;
      ++i;
    }
  return (result);
}

int			get_if_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

char			*my_strncpy(char *s1, char *s2, size_t n)
{
  size_t		i;

  i = 0;
  while (i < n)
    {
      s1[i] = s2[i];
      ++i;
    }
  s1[i] = 0;
  return (s1);
}

char			*my_strcpy(char *dest, char *src)
{
  int			i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = 0;
  return (dest);
}
