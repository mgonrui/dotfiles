#include <ctype.h>
#include <stdio.h>

char capitalize (char str_lowercase[]){
    int i = 0; 
    char str_uppercase[] = {};
    while (str_lowercase[i++] != '\0'){
        str_uppercase[i] = toupper(str_lowercase[i]);
    }
    return str_uppercase;
}

int main(void){
    
    printf("%c",capitalize("hello world1234"));
    return 0;
}