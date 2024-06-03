#include <stdio.h>
#include <string.h>

void reverse(char *c){

char *endptr = c + strlen(c) - 1;
while (endptr >= c){
    printf("%c", *endptr--);
}
printf("\n");
}

int main(void) {
  char message[100];
  
  strcpy(message,"Don't get mad, get even.");
 
  printf("%s\n",message);
 
  reverse(message);
  //printf("%s\n",message);
  
}