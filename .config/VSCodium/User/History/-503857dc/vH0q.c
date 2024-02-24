#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension){

    while (file_name != '\0' ){
        if (file_name == '.'){
            strcpy(*extension, *file_name);
        }

        file_name++;
    }
}

int main(void){
    char ext[100] = {};
    char str[10] = "memo.txt";
    get_extension(&str[0], &ext[0]);
    printf("%s", ext);
    
    return 0;
}