//
// my.h for cpp in /home/maxime/rendu/poule_d01/ex00
// 
// Made by Maxime Brunet
// Login   <maxime1.brunet@epitech.eu>
// 
// Started on  Mon Feb 13 11:39:30 2017 Maxime Brunet
// Last update Mon Feb 13 12:08:21 2017 Maxime Brunet
//

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define NB_BY_ROW 4

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	**str_to_int_tab(char *str);
int	find_nb_lines(int nbr_int);
int	**my_alloc_int_tab(int nbr_int);

#endif
