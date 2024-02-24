#include <stdio.h>

int ft_strlen(char *str)
{
    int size = 0;
    while (str[size] != '\0')
    {
        size++;
    }
    return size;
}

char    *ft_strrev(char *str)
{
    int i_start = 0;
    int i_end = ft_strlen(str -1);
    printf("%d", i_end);
    char swap;
    // while (i_start < i_end)
    // {
    //     swap = str[i_start];
    //     str[i_start] = str[i_end];
    //     str[i_end] = swap;
    //     i_start++;
    //     i_end--;
    // }
    
    return str;
}

int main(void)
{
    char str[] = "123456789";
    printf("original string: %s\n", str);
    ft_strrev(str);
    // printf("reversed string: %s\n",ft_strrev(str));
    // printf("reversed string: %s\n", str);
    return 0;
}
