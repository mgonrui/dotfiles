#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int count = 0;
    while (count < n)
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
        count++;
    }
        return 0;
}
char *ft_strstr(char *str, char *to_find)
{
    int to_find_size = -1;
    while (to_find[to_find_size] != '\0')
    {
        to_find_size++;
    }
    
    while (*str != '\0')
    {
        if(ft_strncmp(str, to_find, to_find_size) == 0)
        {
            return str;
        }         
        str++;
    }
}
int main(void)
{
    char *s1 = "hello world", *s2 = "orl";
    printf("%s", ft_strstr(s1, s2));
    return 0;
}