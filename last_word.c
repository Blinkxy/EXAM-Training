#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}

int main(int ac, char **av)
{
    int i;
    int len;
    int k;
    if (ac == 2)
    {
        i = 0;
        len = ft_strlen(av[1]) - 1;
            while(av[1][len] && (av[1][len] == ' ' || av[1][len] == '\t') && len >= 0)
                len--;
            k = len;
            while(av[1][len] && av[1][len] != ' ' && av[1][len] != '\t')
            len--;
            if(av[1][len] == ' ' || av[1][len] == '\t')
                len = len + 1;
            while(len <= k)
            {
                write(1, &av[1][len], 1);
                len++;
            }
    }
    write(1, "\n", 1);
    return(0); 
}