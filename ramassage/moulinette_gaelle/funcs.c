/*
** funcs.c for poule_d01 in /home/obadia_b/Rendu/poule_d01
** 
** Made by Bryan Obadia
** Login   <obadia_b@epitech.net>
** 
** Started on  Mon Feb 13 10:29:27 2017 Bryan Obadia
** Last update Mon Feb 13 11:09:53 2017 Bryan Obadia
*/

#include "str_to_int_tab.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	rb_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	{
	  my_putchar(str[i]);
	  i++;
	}
    }
}

void	rb_print_err(char *str)
{
  write(2, str, rb_strlen(str));
}

void	rb_xerror(char *str)
{
  write(2, "Error :", 8);
  rb_print_err(str);
  my_putchar('\n');
}

int	rb_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char    *rb_substr(char *str, int start, int nbChar)
{
  int   i;
  int   j;
  char  *str2;

  i = 0;
  j = (start + nbChar);
  if (str == NULL)
    rb_xerror("rb_substr: str has a NULL value.");
  if (start > rb_strlen(str))
    rb_xerror("rb_substr: start is longer than str lenght.");
  if ((start + nbChar) > rb_strlen(str))
    rb_xerror("rb_substr: start + nbChar is longer than str lenght.");
  str2 = malloc(nbChar + 1);
  while (start != j)
    {
      str2[i] = str[start];
      i++;
      start++;
    }
  str2[i] = '\0';
  return (str2);
}
