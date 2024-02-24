#include <stdio.h>
#include <stdlib.h>

int count_str(char* str, int* sum)
{
    int i;
    i = 0;
    while (str[i] != 0)
    {
        i++;
        (*sum)++;
    }
    return i;
}

int ft_count_strs(int size, char** strs, char* sep)
{
    int i = 0, sum = 0;
    while (i < size)
    {
        count_str(strs[i], &sum);
        count_str(sep, &sum);
        count_str(strs[i], &sum);
        i++;
        i++;
    }
    return sum;
}
char *ft_strjoin(int size, char **strs, char *sep)
{
    if (size == 0)
    {
        return "";
        //TODO liberar con free
    }
    printf("%d\n", ft_count_strs(size, strs, sep));
    char *strjoin = malloc ( sizeof(char) * (ft_count_strs(size, strs, sep)));
    return "";

}

int main(void)
{
    int size = 3;
    char *sep = "-";
    char *strs[3] = {"1234567", "8", "9"};
    // ft_strjoin(size, &strs, sep);
    printf("%d\n", ft_count_strs(size, strs, sep));
    return 0;

}