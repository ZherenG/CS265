#include <stdio.h>
#include <string.h>

int x = 0;
struct books {
  int id;
  char title[50];
  char author[50];
}typedef book;
struct books file[5];
//   {0,"The Da Vinci Code", "by Dan Brown"},  
//   {1,"Twilight", "by Stephanie Meyer"},   
//   {2,"To Kill a Mockingbird", "by Harper Lee"},    
//   {3,"The Godfather", "by Mario Puzo"},
//   {4,"Little Women", "by Louisa May Alcott"},      
// };
void createbook(struct books *name, int id, char *title,char *author){
  
  name->id = id;
  strcpy(name->title,title);
  strcpy(name->author,author);
  
}
void insertbook(struct books *name){
  
  file[x] = *name;
  x++;
}

void printbook(struct books *name){
  printf( "%s %s\n", name->title,name->author);
}
void printlist(){
  int p;
  for(p=0;p<5;p++){
    printbook(&file[p]);
  }
  
}

int main(void) {
struct books book1;
createbook(&book1, 1,"The Da Vinci Code,", "by Dan Brown");
printbook(&book1);
insertbook(&book1);
struct books book2;
createbook(&book2, 2,"Twilight,", "by Stephanie Meyer");
printbook(&book2);
insertbook(&book2);
struct books book3;
createbook(&book3, 3,"To Kill a Mockingbird,", "by Harper Lee");
printbook(&book3);
insertbook(&book3);
struct books book4;
createbook(&book4, 4,"The Godfather,", "by Mario Puzo");
printbook(&book4);
insertbook(&book4);
struct books book5;
createbook(&book5, 5,"Little Women,", "by Louisa May Alcott");
printbook(&book5);
insertbook(&book5);


printf("\n");
printf("To show Difference between first set of prints and print list\n");
printf("\n");


  
printlist(&file[5]);
  
}