#include <stdio.h>
#include <string.h>


int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {

        i++;
    }
    
}

int main(void)
{
    char s1[] = "az";
    char s2[] = "ay";
    // printf("%d\n",ft_strcmp(s1, s2));
    printf("%d\n",strcmp(s1, s2));
    return 0;
}