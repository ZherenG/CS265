#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
int main()
{
  FILE *lorum;
  FILE *count;
  //char ce[SIZE];
  int len;
  int num=0;
  int x=0;
   if((lorum = fopen("lorum.txt", "r")) == NULL){
        printf("No File\n");
        exit(1);
    }
  if((count = fopen("count.txt", "w")) == NULL){
        printf("No File\n");
        exit(1);
    }

 while((len = getc(lorum) )!= EOF){
        if (len == '\n'){
            x++;
            
          
          fprintf(count,"%d:%d \n",x,num-1);
          num = 0;
          }
       num++;
      //fprintf(count,"%d:%d \n",num,x);
      //printf("%c", len);
    }
fprintf(count,"%d:%d \n",x+1,num-1);
  
  
fclose(lorum);
fclose(count);

  
  return 0;
}