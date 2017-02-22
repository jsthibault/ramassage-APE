/*
** point.h for point.h in /home/mowgli/cminar/ramassage/correction/poule_d01/ex01
**
** Made by mowgli
** Login   <mowgli@epitech.net>
**
** Started on  Tue Feb 14 15:45:45 2017 mowgli
** Last update Tue Feb 14 15:46:26 2017 mowgli
*/

#ifndef POINT_H_
# define POINT_H_

typedef struct	s_list
{
  int		id;
  char		*name;
  struct s_list	*next;
}		t_list;

void    push_back(t_list **, t_list *);
void    pop_back(t_list **ptr);
t_list  *get_back(t_list *ptr);
t_list  *get_by_index(t_list *ptr,int i);
int     get_size(t_list *ptr);

#endif /* !POINT_H_ */
