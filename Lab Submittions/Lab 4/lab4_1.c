#include <stdio.h>

int main() {
  int num;
  int twanty;
  int tens;
  int fives;
  int ones;
  printf("Enter a dollar amount \n");
  scanf("%d", &num);
  twanty = num/20;
  num = num%20;
  tens = num/10;
  num = num%10;
  fives = num/5;
  num = num%5;
  ones = num;
  

  printf("20$ Bills: %d \n10$ Bills: %d \n5$ Bills: %d \n1$ Bills: %d \n",twanty,tens,fives,ones);





  return 0;
  
}