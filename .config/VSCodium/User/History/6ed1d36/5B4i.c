#include <stdio.h>
#include <string.h>

char    *ft_strcpy(char *s1, char *s2)
{

}

int main(void)
{
    char s1[] = "hello ";
    char s2[] = "worlddddddddddddddddd";
    // ft_strcpy(s1, s2);
    strcpy(s1, s2);
    printf("%s\n", strcpy(s1, s2));
    printf("%s\n", s1);
    printf("%s\n", s2);
}