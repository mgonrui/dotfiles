#include <stdio.h>
#include <unistd.h>

void *ft_print_memory(void *addr, unsigned int size){
    printf("%p\n",&addr);
    // return addr;
}

void *hex_converter( char *char_to_convert){
    char *char_converted, h1, h2;
    int ascii;
    // while (char_to_convert){
        ascii = *char_to_convert;  
        h1 = ascii;
        printf("%d", ascii);
        printf("%d", h1);
        char_to_convert++;
        char_converted++;
    // }
}

int main(void){
    char address[] = "Bonjour les amin";
    // ft_print_memory(&address, 6);
    hex_converter("h\n");
    return 0;
}