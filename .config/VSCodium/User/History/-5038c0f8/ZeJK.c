#include <ctype.h>
#include <stdio.h>

int capitalize (char str_lowercase[]){
    int i = 0; 
    char str_uppercase[30];
    while (str_lowercase[i] != '\0'){
        str_uppercase[i] = toupper(str_lowercase[i]);
        printf("%c", str_uppercase[i]);
        i++;
    }
    return 0;
}

int main(void){
    
    capitalize("hello world1234");
    return 0;
}