#include <stdio.h>
#include <stdlib.h>

int count_str(char* str)
{
    int i;
    i = 0;
    while (str[i] != 0)
    {
        i++;
    }
    return i;
}

int ft_count_strs(int size, char** strs, char* sep)
{
    int i = 0, sum = 0;
    while (i < size)
    {
        sum += count_str(strs[i]);
        sum += count_str(sep);
        i++;
    }
    sum -= count_str(sep);
    return sum;
}
char *ft_strjoin(int size, char** strs, char* sep)
{
    if (size == 0)
    {
        return "";
        //TODO liberar con free
    }
    // printf("%d\n", ft_count_strs(size, strs, sep));
    char* strjoin = malloc ( sizeof(char) * ((ft_count_strs(size, strs, sep) + 1)));
    int i = 0;
    int j = 0;
    while (strs[i][j] != '\0')
    // printf("%d", **strs);
    // while (**strs != '\0')
    {
        printf("%c", strs[i][j]);
        // printf("a");
        j++;
        // strs++;
    }
    
    return "";

}

int main(void)
{
    int size = 3;
    char* sep = "-";
    char* strs[3] = {"1234567", "8", "9"};
    ft_strjoin(size, strs, sep);
    // printf("%d\n", ft_count_strs(size, strs, sep));
    return 0;

}