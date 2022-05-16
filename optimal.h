#ifndef OPTIMAL_H
#define OPTIMAL_H

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define max_size 8
#define max 100
#define swap 8

char    *ft_initialise(void);
char    **ft_voisin(char *i);
int     ft_convert(char *i);
int     ft_function(char *x);
char    *solution_finale(int fd);
char    **ft_swap(char *i);


#endif