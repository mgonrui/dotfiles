#include <stdio.h>
#include <unistd.h>

// void *ft_print_memory(void *addr, unsigned int size){
    // printf("%p\n",&addr);
    // return addr;
// }

void *hex_converter( char *char_to_convert){
    char *char_converted, h1, h2, hex_letters[] = "0123456789ABCDEF";
    int ascii;
    while (*char_to_convert){
        ascii = *char_to_convert;  
        h1 = ascii / 16;
        h2 = hex_letters[ascii % 16];
        printf("hex: %d%c\n", h1, h2);
        *char_converted = "4ersadf";
        char_to_convert++;
        char_converted++;
    }
}

int main(void){
    char address[] = "Bonjour les amin";
    // ft_print_memory(&address, 6);
    hex_converter("hello");
    return 0;
}