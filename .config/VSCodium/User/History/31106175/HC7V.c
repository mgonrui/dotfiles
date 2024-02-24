#include <stdio.h>
#include <unistd.h>

// void *ft_print_memory(void *addr, unsigned int size){
    // printf("%p\n",&addr);
    // return addr;
// }

void *hex_converter( char *char_to_convert){
    char char_converted[100], h1, h2, hex_letters[] = "0123456789ABCDEF";
    int ascii, count = 0;
    while (*char_to_convert){
        ascii = *char_to_convert;  
        h1 = hex_letters[ascii / 16];
        h2 = hex_letters[ascii % 16];
        char_converted[count++] = h1;
        char_converted[count++] = h2;
        char_to_convert++;
    }
    printf("char converted: %s", char_converted);
}

int main(void){
    char address[] = "Bonjour les amins";
    // ft_print_memory(&address, 6);
    hex_converter(address);
    return 0;
}