int ft_str_is_alpha(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] >= '0' && str[i] <= '9'))
        {
            i++;
        }
        else
        {
            return 0;
        }
        return 1;
        
    }
    

}

int main(void)
{
    char str[] = "1234";
    printf("%d\n", ft_str_is_alpha(str));
}