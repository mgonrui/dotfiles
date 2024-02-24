#include <stdio.h>
#include<string.h>

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' || *s2 !='&&')
    {
        if ( *s1 == *s2)
        {
            ;
        }
        else if (*s1 == '\0' && *s2 != '\0')
        {
            return -1;
        }
        else if (*s2 == '\0' && *s1 != '\0')
        {
            return 1;
        }
        else if (*s1 > *s2)
        {
            return (*s1 - *s2);
        }
        else if (*s2 > *s1)
        {
            return (*s2 - *s1);
        }
        s1++;
        s2++;
        
    }
    

}

int main(void)
{
    char *st1 = "a", *st2 = "aa";
    printf("%d\n", strcmp(st1, st2));
//    printf("%d\n", ft_strcmp(st1, st2));
    return 0;
}