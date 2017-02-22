#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memstream.h"

int **str_to_int_tab(char *s);
int **str_to_int_tab_own(char *s);

// Mettre NB_BY_ROW number of numbers by line
// remplir dernière ligne avec des 0 s'il n'y a pas assez d'éléments
// mettre -1 pour marquer la fin du tableau

int	print_int_tab(int **tab, char **data, size_t *data_size)
{
    FILE* f = open_memstream(data, data_size);
    for (int i = 0; tab[i][0] != -1; ++i)
    {
        for (int j = 0; j < NB_BY_ROW; ++j)
        {
            if (j == 0)
                fprintf(f, "%d", tab[i][j]);
            fprintf(f, " %d", tab[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    return 0;
}

int their_test(char const* in, char **data, size_t *data_size)
{
    char* s = strdup(in);
    int **tab = str_to_int_tab(s);
    print_int_tab(tab, data, data_size);
    return 0;
}

int our_test(char const* in, char **data, size_t *data_size)
{
    char* s = strdup(in);
    int **tab = str_to_int_tab_own(s);
    print_int_tab(tab, data, data_size);
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        char *their = NULL;
        size_t their_size = 0;
        their_test(av[1], &their, &their_size);

        char *our = NULL;
        size_t our_size = 0;
        our_test(av[1], &our, &our_size);

        if (their_size != our_size)
            return EXIT_FAILURE;

        if (memcmp(their, our, our_size) != 0)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
