/*
** main_list.c for  in /Users/mowgli
**
** Made by Mowgli
** Login   <Mowgli@epitech.net>
**
** Started on  Thu Jan 26 10:29:54 2017 Mowgli
** Last update Tue Feb 14 10:39:49 2017 mowgli
*/

#include "point.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int		main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
  t_list	*ptr = NULL;
  t_list	new;
  t_list	new_2;
  t_list	*tmp;

  new_2.id = 8080;
  new_2.name = "HTTP";
  new_2.next = NULL;
  new.id = 443;
  new.name = strdup("HTTPS");
  new.next = NULL;
  push_back(&ptr, &new);
  tmp = get_back(ptr);
  printf("%d -- %s\n", tmp->id, tmp->name);
  push_back(&ptr, &new_2);
  tmp = get_back(ptr);
  printf("%d -- %s\n SIZE : %d\n", tmp->id, tmp->name, get_size(ptr));
  tmp = get_by_index(ptr, get_size(ptr) - 1);
  printf("%d -- %s\n", tmp->id, tmp->name);
  pop_back(&ptr);
  tmp = get_back(ptr);
  printf("%d -- %s\n SIZE : %d\n", tmp->id, tmp->name, get_size(ptr));
  //  pop_back(&ptr);
  //printf("SIZE : %d\n", tmp->id);
  return (0);
}
