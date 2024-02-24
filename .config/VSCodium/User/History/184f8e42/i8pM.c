#include <stdio.h>
#include <string.h>

char *ft_strstr(char *str, char *to_find)
{

}

int main(void)
{
    char str[] = "hello world!";
    char to_find[] = "worl";
    char *found = strstr(str, to_find);
    // char found[] = ft_strstr(str, to_find);
    printf("%s\n", found);
    return 0;
}