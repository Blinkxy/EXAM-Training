#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void putnbr(int n)
{
    if ( n == -2147483648)
        write(1, "-2147483648", 11);
    if ( n < 0)
    {
        ft_putchar('-');
        n *= -1;
    }
    if ( n / 10 > 0)
        putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}

int ft_atoi(char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9' && str[i])
    {
        res = (res * 10) + str[i] - '0';
        i++;
    }
    return(res * sign);
}

int is_prime(int n)
{
    if (n <= 1)
        return(0);
    int i = 2;
    while(i * i <= n)
    {
        if( n % i == 0)
            return(0);
        i++;
    }
    return(1);  
}
int main(int ac, char **av)
{
    int i;
    int n;

    if (ac == 2)
    {
        i = 1;
        n = atoi(av[1]);
        if( n == 1)
            printf("1");
        while(n >= ++i)
        {
            if( n % i == 0 && is_prime(i))
            {
                printf("%d", i);
                if (n == i)
                    break;
                printf("*");
                n /= i;
                i = 1;
            }
        }
    }
    printf("\n");
    return(0);
}
