#include <stdio.h>
#include <string.h>


int ft_strcmp(char *s1, char *s2)
{
    return (s1 - s2);
}

int main(void)
{
    char s1[] = "h";
    char s2[] = "h";
    printf("%d\n",ft_strcmp(s1, s2));
    printf("%d\n",strcmp(s1, s2));
    return 0;
}