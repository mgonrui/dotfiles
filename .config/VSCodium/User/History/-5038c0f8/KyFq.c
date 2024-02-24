// #include <ctype.h>
// #include <stdio.h>

// int capitalize (char str[]){
//     char *p_str = &str[0]; 
//     while (*p_str != '\0'){
//         *p_str = toupper(*p_str);
//         printf("%c", *p_str);
//         p_str++;
//     }
//     return 0;
// }

// int main(void){
    
//     capitalize("hello world1234");
//     return 0;
// }

#include <ctype.h>
#include <stdio.h>

int capitalize (char str[]){
    char *p_str = &str[0]; 
    while (*p_str != '\0'){
        *p_str = toupper(*p_str);
        printf("%c", *p_str);
        p_str++;
    }
    return 0;
}

int main(void){
    
    capitalize("hello world1234");
    return 0;
}