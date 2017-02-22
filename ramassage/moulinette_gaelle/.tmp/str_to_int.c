/*
** str_to_int.c for  in /home/millot_b/B4_Module/CPP-minar/d01/poule_d01/ex00
**
** Made by Damien Millot
** Login   <@epitech.eu>
**
** Started on  Mon Feb 13 10:19:38 2017 Damien Millot
** Last update Mon Feb 13 11:58:14 2017 Damien Millot
*/

#include "str_to_int.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void			count_elem(t_stock *stock, char *str)
{
  int			i;

  stock->nb_elem = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	stock->nb_elem++;
      i++;
    }
  stock->nb_elem++;
}

int			stock_tab(t_stock *stock, char *str)
{
  int			i;
  int			k;
  int			j;

  i = 0;
  if ((stock->tab_s = malloc(sizeof(char) * 100)) == NULL)
    return (-1);
  while (i < 10)
    if ((stock->tab_s[i++] = malloc(sizeof(char) * 10)) == NULL)
      return (-1);

  i = 0;
  k = 0;
  j = 0;
  while (str[k])
    {
      stock->tab_s[i][j++] = str[k++];
      if (str[k] == ' ')
	{
	  stock->tab_s[i][j] = '\0';
	  i++;
	  k++;
	  j = 0;
	}
    }
  stock->tab_s[i] = '\0';
  return (0);
}

int			**str_to_int_tab(char *str)
{
  t_stock		stock;
  int			rows;
  int			rows_int;
  int			column;
  int			i;
  rows = 0;
  column = 0;
  count_elem(&stock, str);
  stock_tab(&stock, str);

  stock.tab_int = malloc(sizeof(int) * my_strlen(str));
  while (rows < my_strlen(str))
    stock.tab_int[rows++] = malloc(sizeof(int) * my_strlen(str));
  rows = 0;

  i = 0;
  rows_int = 0;
  while (stock.tab_s[rows])
    {
      stock.tab_int[column][rows_int++] = atoi(stock.tab_s[rows++]);
      if (rows_int == NB_BY_ROW)
	{
	  column++;
	  rows_int = 0;
	}
    }
  while (rows_int < NB_BY_ROW)
    rows_int++;
  stock.tab_int[column][rows_int] = -1;
  return (stock.tab_int);
}
