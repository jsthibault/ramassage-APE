//
//  str_to_tab.c
//  poule_d01
//
//  Created by Yoahn Linard on 13/02/2017.
//  Copyright © 2017 Yoahn Linard. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_to_int_tab.h"


char	**malloc_tab(int ligne, int colonne)
{
    if (ligne <= 0 || colonne <= 0)
    {
        write(2, "error: malloc_tab: array is NULL \n",
              strlen("error: malloc_tab: array is NULL \n"));
        exit(84);
    }
    char	**tab;
    int	n;
    
    n = 0;
    if ((tab = malloc(sizeof(char *) * (ligne))) == NULL)
    return (NULL);
    while (n != ligne)
    {
        if ((tab[n] = malloc(sizeof(char) * colonne)) == NULL)
        return (NULL);
        n = n + 1;
    }
    return (tab);
}

int	compt_char(char *str, char delim)
{
    int		word;
    int		nb;
    
    word = 1;
    nb = 0;
    while (*str)
    {
        if (delim == *str)
        word = 1;
        else if (word == 1)
        {
            nb++;
            word = 0;
        }
        str++;
    }
    return (nb);
}

char	**return_tab_malloc(char *str, char delim)
{
    int	ligne;
    int	colonne;
    char	**tab;
    
    ligne = compt_char(str, delim) + 1;
    colonne = my_strlen(str);
    tab = malloc_tab(ligne, colonne);
    return (tab);
}

int	in_str(char *str, char to_test)
{
    while (*str)
    {
        if (to_test == *str)
        return (1);
        str++;
    }
    return (0);
}

int	count_tab(char **tab)
{
    int	i;
    
    i = 0;
    while (tab[i])
    i++;
    return (i);
}

char	**str_to_tab(char *str, char delim)
{
    int	i;
    int	j;
    int	n;
    char	**tab;
    
    i = 0;
    j = 0;
    n = 0;
    tab = return_tab_malloc(str, delim);
    while (str[n] != '\0')
    {
        if (str[n] == delim)
        {
            i++;
            j = 0;
            n++;
        }
        tab[i][j++] = str[n++];
    }
    tab[i] = NULL;
    return (tab);
}
