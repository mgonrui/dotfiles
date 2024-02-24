#include <stdio.h>
#include <unistd.h>

// void *ft_print_memory(void *addr, unsigned int size){
    // printf("%p\n",&addr);
    // return addr;
// }

void *hex_converter( char *char_to_convert){
    char char_converted[100], h1, h2, hex_letters[] = "0123456789ABCDEF";
    int ascii, count = 0, space_count;
    while (*char_to_convert){
        ascii = *char_to_convert;  
        h1 = hex_letters[ascii / 16];
        h2 = hex_letters[ascii % 16];
        char_converted[count++] = h1;
        char_converted[count++] = h2;
        char_to_convert++;
        write(1, (char_converted + count - 2), 1);
        write(1, (char_converted + count -1), 1);
        // if ((count % 4) == 0)
        // {
        //     write(1, " ", 1);
        // }
    }
    printf("\nchar converted: %s", char_converted);
}

int main(void){
    char address[] = "Bonjour les amin";
    // ft_print_memory(&address, 6);
    hex_converter(address);
    return 0;
}