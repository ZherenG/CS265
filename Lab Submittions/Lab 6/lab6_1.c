#include <stdio.h>
#include <string.h>

void reverse(char *c){
  char *endptr = c + strlen(c) - 1;
int counter;

counter = strlen(c) - 1;

while (counter >= 0){
    printf("%c", c[counter]);
    --counter;

  }
  printf("\n");
}

int main(void) {
  char message[100];
  
  strcpy(message,"Don't get mad, get even.");
 
  printf("%s\n",message);
 
  reverse(message);
  
  
}