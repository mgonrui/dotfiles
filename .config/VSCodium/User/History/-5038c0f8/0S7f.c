#include <ctype.h>
#include <stdio.h>

// void capitalize (char *str){
//     char *p_str = str; 
//     while (*p_str != '\0'){
//         *p_str = toupper(*p_str);
//         printf("%c", *p_str);
//         p_str++;
//     }
// }
void capitalize(char * str){
  char *p = str;
  while(*p != '\0')
	{
	  if(isalpha(*p)) {
	    *p = toupper(*p);
	  }
	  p++;
	}
}

int main(void){
    
    capitalize("h");
    return 0;
}