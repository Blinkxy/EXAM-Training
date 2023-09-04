#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void putnbr(int n)
{
    if ( n / 10 > 0)
        putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}

int main(int ac, char **av)
{
    (void)av;
    if (ac > 1)
    {
        putnbr(ac - 1);
        write(1, "\n", 1);
    }
    else
        write(1, "0\n", 2);
    return(0); 
}