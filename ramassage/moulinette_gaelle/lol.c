/*
** str_to_int_tab.c for  in /home/nathan/rendu/poule_d01/ex00
**
** Made by nathan
** Login   <nathan.szwec@epitech.eu>
**
** Started on  Mon Feb 13 10:23:30 2017 nathan
** Last update Feb Feb 13 11:49:30 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_a_number(char c)
{
  if((c >= '0') && (c <= '9'))
    return 1;
  return 0;
}

int char_to_int(char c)
{
  int nbr;
  nbr = 0;

  while (c && (c >= '0' && c <= '9'))
  {
      nbr *= 10;
      nbr += c - '0';
      c += 1;
  }
  printf("%d\n", nbr);
  return (nbr);
}

int ft_atoi(char *str)
{
  int  i;
  int  nb;
  int  tmp;

  i = 0;
  nb = 0;
  tmp = strlen(str);
  if (tmp > 1)
     --tmp;
  else
     tmp = 1;
  while (str[i] != '\0')
  {
     if (str[i] >= '0' && str[i] <= '9')
     {
       nb += (str[i] - 48) * 10^tmp;
       --tmp;
     }
     ++i;
   }
   printf("%d\n", nb);
   return nb;
}

int main()
{
  char *c;

  c = "512";
  ft_atoi(c);
  printf("%d\n", atoi(c));
}
