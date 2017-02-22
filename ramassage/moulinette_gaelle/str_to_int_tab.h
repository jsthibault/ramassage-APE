//
//  str_to_int_tab.h
//  poule_d01
//
//  Created by Yoahn Linard on 13/02/2017.
//  Copyright © 2017 Yoahn Linard. All rights reserved.
//

#ifndef str_to_int_tab_h
#define str_to_int_tab_h

#include <stdio.h>
#include <unistd.h>

int             **str_to_int_tab(char *str);
int             my_getnbr(char *str);
char            **str_to_tab(char *str, char delim);
int             count_tab(char **tab);
int             my_strlen(char *str);

#endif /* str_to_int_tab_h */
