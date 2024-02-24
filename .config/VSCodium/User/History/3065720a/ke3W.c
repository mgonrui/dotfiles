#include <stdio.h>
#include <string.h>


int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int i = 0;
    while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }
    if (i == n)
    {
        i--;
    }
    return (s1[i] - s2[i]);
}

int main(void)
{
    char s1[] = "az123";
    char s2[] = "ab";
    int n = 3;
    printf("%d\n",ft_strncmp(s1, s2, n));
    printf("%d\n",strncmp(s1, s2, n));
    return 0;
}