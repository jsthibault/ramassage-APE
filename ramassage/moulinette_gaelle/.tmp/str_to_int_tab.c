#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int get_nb(char *str)
{
int nb = 0;
int neg = 0;

if (str == NULL)
return (-10);
for (int i = 0; str[i] != '\0'; i++)
{
if (str[i] == '-')
++neg;
else
{
nb *= 10;
nb += (str[i] - 48);
}
}
return (neg % 2 == 0 ? nb : -nb);
}

int space_count(char *str)
{
int cnt = 0;

for (int i = 0; str[i] != '\0'; i++)
if (str[i] == ' ')
++cnt;
return (cnt + 1);
}

int **str_to_int_tab(char *str)
{
int line_nb = (space_count(str) /  NB_BY_ROW) + 2;
int **ret = malloc(sizeof(int *) * (line_nb));
char  *val;
int cnt = -1;
int j;

if (!ret)
return (NULL);
for (int i = 0; i < line_nb; i++)
if (!(ret[i] = malloc(sizeof(int) * NB_BY_ROW)))
return (NULL);
for (int i = 0; i < line_nb; ++i)
{
for (int j = 0; j < NB_BY_ROW; ++j)
{
if (i + 1 < line_nb)
ret[i][j] = 0;
else
ret[i][j] = -1;
}
}
j = 0;
val = strtok(str, " ");
while (val != NULL)
{
ret[j][++cnt] = get_nb(val);
if (cnt + 1 == NB_BY_ROW)
{
cnt = -1;
++j;
}
val = strtok(NULL, " ");
}
return (ret);
}
