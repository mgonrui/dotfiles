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
        return ((char* )malloc (sizeof (char))); 
    }
    char* strjoin = malloc ( sizeof(char) * ((ft_count_strs(size, strs, sep) + 1)));
    int i = 0;
    int k = 0;
    while (i < size)
    {
        int j = 0;
        while (strs[i][j] != '\0')
        {
            strjoin[k++] = strs[i][j];
            j++;
        }
        j = 0;
        if (i < size -1)
        {
            while (sep[j] != '\0')
            {
                strjoin[k++] = sep[j] ;
                j++;
            }
        }
        i++;
    }
    return strjoin;
}

int main(void)
{
    int size = 3;
    char* sep = "...";
    char* strs[3] = {"hello", "world", "!!!"};
    printf("%s\n",ft_strjoin(size, strs, sep));
    // printf("%d\n", ft_count_strs(size, strs, sep));
    return 0;

}