/*
** getnbr.c for getnbr in /home/bocage_c/poubelle
** 
** Made by Bocage Chloé
** Login   <bocage_c@epitech.net>
** 
** Started on  Wed Jan  4 18:05:38 2017 Bocage Chloé
** Last update Mon Feb 13 11:00:41 2017 Bocage Chloé
*/

int	getnbr(const char *str)
{
  int i = 0;
  int cpt = 1;
  int nb = 0;

  while (str[i] < 48 || str[i] > 58)
    {
      if (str[i] == '-')
	cpt = cpt * -1;
      ++i;
    }
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
      nb = nb * 10;
      nb = nb + (str[i] - 48);
      ++i;
      if (nb > 214748364)
	return (0);
      else if (nb > 214748363 && str[i] > '7')
	return (0);
    }
  return (nb * cpt);
}
