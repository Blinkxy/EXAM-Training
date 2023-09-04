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
    int j;
    int len;
    if (ac > 1)
    {
        i = 1;
        while(av[i])
        {
            j = 0;
            len = ft_strlen(av[i]) - 1;
            while(av[i][j])
            {
                if(av[i][j] >= 'A' && av[i][j] <= 'Z')
                    av[i][j] += 32;
                j++;
            }
            while(len > 0)
            {
                while((av[i][len] == ' ' || av[i][len] == '\t') && av[i][len] && av[i][len] < 'a' && av[i][len] > 'z')
                    len--;
                if( len > 0 && av[i][len] >= 'a' && av[i][len] <= 'z' && (av[i][len + 1] == ' ' || av[i][len + 1] == '\t'))
                    av[i][len] = av[i][len] - 32;
                if (av[i][0] >= 'a' && av[i][0] <= 'z' && (av[i][1] == ' ' || av[i][1] == '\t'))
                    av[i][0] -= 32;
                if (av[i][len] >= 'a' && av[i][len] <= 'z' && !av[i][len + 1])
                    av[i][len] = av[i][len] - 32;
                len--;
            }
            j = 0;
            while(av[i][j])
            {
                write(1, &av[i][j], 1);
                j++;
            }
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}