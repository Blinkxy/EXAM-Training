#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

int count_words(char *str)
{
    int i = 0;
    int count = 0;
    
    while(str[i])
    {
        while((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
            i++;
        if(str[i])
            count++;
        while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
    }
    return(count);
}

char *ft_strncpy(char *s1, char *s2, int n)
{
    int i = -1;
    while(++i < n && s2[i])
        s1[i] = s2[i];
    s1[i] = '\0';
    return(s1);
}

char    **ft_split(char *str)
{
    int i;
    int j;
    int k;
    int count = count_words(str);
    char **split;

    split = (char **)malloc(sizeof(char *) * count + 1);
    if(!split)
        return(NULL);

    i = 0;
    j = 0;
    while(str[i])
    {
        while((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
            i++;
        if(str[i])
        {
            k = i;
            while( str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
                i++;
            if ( i > k)
                split[j] = malloc(sizeof(char) * (i - k) + 1);
            if(!split[j])
                return(NULL);
            split[j] = ft_strncpy(split[j],&str[k], i - k);
            j++;
        }
    }
    split[j] = NULL;
    return(split);
}

int main()
{
    char str[] = "  \nHELLO   \n my/dude \t hi  hey";
    char **split = ft_split(str);

    int i = 0;
    while(split[i])
    {
        printf("%s\n", split[i]);
        i++;
    }
    return(0); 
}


