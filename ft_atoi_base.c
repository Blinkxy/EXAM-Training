int     ft_atoi_base(const char *str, int str_base)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    if (str_base < 1 || str_base > 16)
        return 0;
    while((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] && ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')))
    {
        if(str[i] >= '0' && str[i] <= '9')
            res = res * str_base + (str[i] - '0');
        else if (str[i] >= 'A' && str[i] <= 'F')
            res = res * str_base + (str[i] - 'A' + 10);
        else if (str[i] >= 'a' && str[i] <= 'f')
            res = res * str_base + (str[i] - 'a' + 10);
        i++;
    }
    return(res * sign);
}