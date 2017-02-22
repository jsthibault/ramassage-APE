/*
** str_to_int_tab.c for  in /home/mellit/tech2/poule_d01
**
** Made by Melliti Ramzi
** Login   <mellit@epitech.net>
**
** Started on  Mon Feb 13 09:13:20 2017 Melliti Ramzi
** Last update Mon Feb 13 11:35:59 2017 Melliti Ramzi
*/

#include <stdlib.h>
#include <stdio.h>


int	my_getnbr(char *str);

int	nword(char *str)
{
int	ct;
int	i;

ct = 0;
i = 0;
while (str[i])
{
while (str[i] == ' ')
i++;
ct += 1;
while (str[i] >= '0' && str[i] <= '9')
i++;
}
return (ct);
}

char		*cword(char *str)
{
char		*dst;
static int	i = 0;
static int	s = 0;
int		idx;

idx = 0;
while (str[i] == ' ')
i++;
s = i;
while (str[i] != ' ' && str[i] != 0)
i++;
dst = malloc(sizeof(char) * i - s + 1);
while (s != i)
dst[idx++] = str[s++];
dst[idx] = 0;
return (dst);
}

char	**str_to_wordtab(char *str)
{
char	**tab;
int	s;

s = 0;
if ((tab = malloc(sizeof(char *) * nword(str) + 1)) == NULL)
return (NULL);
tab[nword(str)] = NULL;
while (s != nword(str))
{
if ((tab[s] = cword(str)) == NULL)
return (NULL);
s++;
}
return (tab);
}

int     neg(char *str, int i)
{
int   nb;

nb = 0;
i++;
if (str[i] < '0' && str[i] > '9')
return (1);
else
{
while (str[i] <= '9' && str[i] >= '0')
{
nb = nb * 10;
nb = nb + str[i] - 48;
i++;
}
}
nb = nb * (-1);
return (nb);
}

int     my_getnbr(char *str)
{
int   nb;
int   i;

nb = 0;
i = 0;
while (str[i] < '0' || str[i] > '9')
{
if (str[i] == '-')
{
if (neg(str, i) < 0)
return (neg(str, i));
}
i++;
if (str[i] == '\0')
return (-1);
}
while (str[i] <= '9' && str[i] >= '0')
{
nb = nb * 10;
nb = nb + str[i] - 48;
i++;
}
return (nb);
}

int	**str_to_int_tab(char *str)
{
char	**ctab;
int	**itab;
int	i;
int	s;
int	a;

a = 0;
i = 0;
s = 0;
itab = malloc(sizeof(int) * nword(str));
ctab = str_to_wordtab(str);
while (a < nword(str))
{
itab[i] = malloc(sizeof(int) * NB_BY_ROW);
while (s < NB_BY_ROW)
{
itab[i][s++] = my_getnbr(ctab[a++]);
if (a >= nword(str))
while (s++ != NB_BY_ROW && a++ <= nword(str))
itab[i][s - 1] = 0;
}
i++;
s = 0;
}
return (itab);
}
