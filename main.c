#include "optimal.h"

int main()
{
    char    *init;
    int     i;
    int     j;

    i = 0;
    init = ft_initialise();
    printf("solution initial c'est : %s\n en decimal %d\n", i , ft_convert(i));
    while (i < max)
    {
        char **str = ft_voisin(init);
        j = 0;
        while (j < max_size)
        {
            if (solution_finale(str[j]) < solution_finale(init))
                init = str[j];
            j++;
        }
        i++;
    }

    printf("solution sous_optimal est: %s\n en decimal: %d", init,ft_convert(init));
    int fd = open("sol.txt", O_RDWR | O_APPEND);
    write(fd, i, max_size);
    if (max != 100)
        write(fd, "\n", 1);

    if (max == 100)
    {
        int fd1 = open("sol.txt", O_RDONLY);
        char *f = final_solution(fd1);
        printf("\nLa solution final est : %s\n En decimal : %d", f, convert(init));
    }
}