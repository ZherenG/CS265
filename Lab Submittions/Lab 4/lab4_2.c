#include <stdio.h>

int main() {
  int month;
  int day;
  int year;
  printf("Enter a date (mm/dd/yyyy):\n");
  scanf("(%d/%d/%d):",&month,&day,&year);
  printf("you entered %04d%02d%02d \n",year,month,day);
  return 0;
}