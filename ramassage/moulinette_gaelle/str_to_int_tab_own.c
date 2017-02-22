#include <string.h>
#include <stdlib.h>

int	**str_to_int_tab_own(char *str)
{
    char * word = NULL;
    word = strtok(str, " ");
    size_t tab_capacity = 10;

    size_t tab_nb = 0;
    size_t tab_current_line = 0;
    int** tab = calloc(sizeof(int *), tab_capacity);
    while (word != NULL)
    {
        if (tab[tab_current_line] == NULL)
        {
            tab[tab_current_line] = malloc(sizeof(int) * NB_BY_ROW);
            if (tab_current_line == tab_capacity)
            {
                tab_capacity *= 2;
                tab = realloc(tab, sizeof(int *) * tab_capacity);
                for (unsigned int i = tab_current_line; i < tab_capacity; ++i)
                    tab[i] = NULL;
            }
        }
        tab[tab_current_line][tab_nb] = atoi(word);
        tab_nb++;
        if (tab_nb % NB_BY_ROW == 0)
        {
            tab_current_line++;
            tab_nb = 0;
        }
        word = strtok(NULL, " ");
    }

    while ((tab_nb % NB_BY_ROW != 0) && tab_nb != 0)
        tab[tab_current_line][tab_nb++] = 0;

    if (tab_nb != 0)
        tab_current_line++;

    if (tab[tab_current_line] == NULL)
    {
        tab[tab_current_line] = malloc(sizeof(int) * NB_BY_ROW);
        if (tab_current_line == tab_capacity)
        {
            tab_capacity *= 2;
            tab = realloc(tab, sizeof(int *) * tab_capacity);
            for (unsigned int i = tab_current_line; i < tab_capacity; ++i)
                tab[i] = NULL;
        }
    }
    for (unsigned int i = 0; i < NB_BY_ROW; ++i)
    {
        tab[tab_current_line][i] = -1;
    }
    return tab;
}
