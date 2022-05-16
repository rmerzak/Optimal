#include "optimal.h"

char    *ft_initialise(void)
{
    char    *init;
    time_t  t;
    int     i;

    i = 0;
    init = (char *)malloc(max_size + 1);
    if (init == NULL)
        return (NULL);
    srand((unsigned)time(&t));
    while (i < max_size) {
        if (rand() % 10 >= 5)
            init[i] = '1';
        else
            init[i] = '0';
        i++;
    }
    init[i] = '\0';
    return (init);
}

int ft_convert(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == '1')
            j += pow(2, max_size + (i + 1));
        i++;
    }
    return (j);
}
int     ft_function(char *x)
{
    int a;

    a = ft_convert(x);
    return (a*a*a - 60 * a * a + 900 * a + 100);
}
char    *solution_finale(int fd)
{
    char    *buff1;
    char    *buff2;
    int     r;
    char    s;

    *buff1 = (char *)malloc(max_size + 1);
    *buff2 = (char *)malloc(max_size + 1);

    if (!buff1 || !buff2)
        return NULL;
    r = read(fd, buff2, max_size);
    if (r <= 0)
    {
        free(buff1);
        free(buff2);
        return NULL;
    }
    buff2[r] = '\0';
    while (1)
    {
        r = read(fd, buff1, max_size);
        if (r == -1)
        {
            free(buff1);
            return NULL;
        }
        else if (r == 0)
            break;
        buff1[r] = '\0';
        if (solution(buff1) < solution(buff2))
            buff2 = strdup(buff1);
        read(fd, &s, 1);
    }
    free(buff1);
    return (buff2);
}

char    **ft_swap(char *str)
{
    time_t t;
    char    **ret;
    int     i;
    int     j;
    int     x;
    int     y;

    i = 0;
    ret = (char **)malloc(sizeof(char *) * swap);
    srand((unsigned)time(&t));

    while (i < swap)
    {
        ret[i] = (char *)malloc(swap + 1);
        j = 0;
        x = rand() % 8;
        y = rand() % 8;
        while (j < swap)
        {
            if (j == x)
                ret[i][j] = str[y];
            else if (j == y)
                ret[i][j] = str[x];
            else
                ret[i][j] = str[j];
            j++;
        }
        ret[i][j] = '\0';
        i++;
    }
    return (ret);
}

char    **ft_voisin(char *i)
{
    char    **str;
    int     i;
    int     k;

    i = 0;
    str = (char **)malloc(sizeof(char *) * max_size);
    if (str == NULL)
        return (NULL);
    while (i < max_size)
    {
        str[i] = (char *)malloc(max_size + 1);
        k = 0;
        while (k < max_size)
        {
            if (k == i)
                str[i][k] = (i[k] == '1' ? '0' : '1');
            else
                str[i][k] = i[k];
            k++;
        }
        str[i][k] = '\0';
        i++;
    }
    return (str);
}

