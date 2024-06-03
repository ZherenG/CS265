#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct sixers{
   char name[100];
  int salery;
  char years[100];
  
};
// struct season{
//     int salery;
//     char years[100];
//     struct season *next;
// };
struct play{
   char name[100];
   int salery;
   char years[100];
   struct play *next;
};

struct sixers players[1000];

//struct play final[1000];

int read_csv(char* file, struct sixers* players){
  FILE *sixer;
  char data[256],*string;
  int count = 0, cols = 0;
  if((sixer = fopen(file, "r")) == NULL){
        printf("No File\n");
        exit(1);
    }
      while(fgets(data, 256, sixer)){
        cols = 0;
        string = strtok(data, ",");
        while (string){
            switch (cols){
            case 0:
                strcpy(players[count].name, string);
                break;
            case 1:
                players[count].salery = atoi(string);
                break;
            case 2:
                strcpy(players[count].years, string);
                break;
            }
            string = strtok(NULL, ",");
            cols++;
        }
        count++;
      }
  return count;
}

int count_list(struct play * head) {
    struct play * current = head;
    int count=0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
  return count;
}

int count_money(struct play * head) {
    struct play * current = head;
    int count=0;
    while (current != NULL) {
        count += current->salery;
        current = current->next;
    }
  return count;
}
int count_money_max(struct play * head) {
    struct play * current = head;
    int count=0;
    while (current != NULL) {
      if(current->salery > count){
        count = current->salery;
      }
        current = current->next;
    }
  return count;
}
void print_list(struct play * head) {
    struct play * current = head;

    while (current != NULL) {
        printf("%s\n", current->name);
        printf("%d\n", current->salery);
        printf("%s\n", current->years);
        current = current->next;
    }
}
void enqueue(struct play** queue, struct play* item){
  struct play *copy = *queue;
  int x;
  if(copy == NULL){ 
    *queue = item;
    return;
  }
  for(x = 0; x < sizeof(copy);x++){
    if(copy->next != NULL){ 
    
    copy = copy->next; 
  }
    }
  copy->next = item; 
  
}

int main(int argc, char *argv[]) {
  FILE *csv;
  char seg[100];
  int c,x;
  int seasons;
  int player; 
  int count = 0; 
  struct play *final[1000];
  final[count] = (struct play*)malloc(sizeof(struct play));
  
  if(argc != 2){
      c = read_csv("sixers.csv", players);
      printf("%d \n",5);
  }
  else{
    c = read_csv(argv[1], players);
  }
  //c = read_csv("sixers.csv", players);
  
  strcpy(final[count]->name, players[count].name);
  final[count]->salery = players[count].salery;
  strcpy(final[count]->years, players[count].years);
  for(x= 1; x < c; x++){
    if(strcmp(players[x].name,final[count]->name)==0){
          struct play *newnode;
          newnode = malloc(sizeof(struct play));
          strcpy(newnode->name , players[x].name);
          newnode->salery = players[x].salery;
          strcpy(newnode->years,players[x].years);
          newnode->next = NULL;
          enqueue(&final[count],newnode);
    }
    else{

      count++;
      final[count] = (struct play*)malloc(sizeof(struct play));
      strcpy(final[count]->name, players[x].name);
      final[count]->salery = players[x].salery;
      strcpy(final[count]->years, players[x].years);
    }
  }
    
    int test;
    int money = count_money(final[test]);
    int moneysolo = count_money_max(final[test]);
    int playerm;
    int playerm2; 
    seasons = count_list(final[test]);
    for(test = 0;test<= count; test++){
      //printf("%d \n",count_list(final[test]));
      if(count_list(final[test]) > seasons){
        player = test;
        seasons = count_list(final[test]);
      }
    if(count_money(final[test]) > money){
        playerm = test;
        money = count_money(final[test]);
      }
    if(count_money_max(final[test]) > moneysolo){
        playerm2 = test;
        moneysolo = count_money_max(final[test]);
      }

}

printf("The Player with the most seasons is %s with %d seasons \n",final[player]->name, seasons);

printf("The Player with the most salery accross all seasons is %s with %d \n",final[playerm]->name,money);

printf("The Player with the most salery in one season is %s with %d \n",final[playerm2]->name, moneysolo);
}

  
