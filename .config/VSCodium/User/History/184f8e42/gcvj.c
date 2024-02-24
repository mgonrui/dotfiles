#include <stdio.h>
#include <string.h>

char *ft_strstr(char *str, char *to_find)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == to_find[0])
        {
            int j = 0;
            while (to_find[j] != '\0')
            {
                j++;
            }
            
        }
        i++;
    }
    

}

int main(void)
{
    char str[] = "hello world!";
    char to_find[] = "rl";
    char *found = strstr(str, to_find);
    // char found[] = ft_strstr(str, to_find);
    printf("%s\n", found);
    return 0;
}