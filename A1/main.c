#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct order {
    char name[25];
    int quantity;
    float price;
    char state[10];
};
struct salesTax {
    char state[25];
    char st_abr[10];
    float sales_tax;
};
struct invoice{
    char tax[100];
    char subtotal[100];
};

struct order orderies[100];
struct salesTax taxlist[100];
struct invoice invoicelist[100];

char *trim_str(char *str)
{
    char *end;

    // trim leading space
    while(isspace((unsigned char)*str)) str++;

    // if all spaces, return
    if(*str == 0)
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end))
        end--;

    // add null terminator character
    end[1] = '\0';

    return str;
}
int read_order(char* file, struct order* orderies){
  FILE *order;
  char orders[256],*string;
  int count = 0, cols = 0;
  if((order = fopen(file, "r")) == NULL){
        printf("No File\n");
        exit(1);
    }
      while(fgets(orders, 256, order)){
        strcpy(orders, trim_str(orders));
        cols = 0;
        string = strtok(orders, ",");
        while (string){
            switch (cols){
            case 0:
                strcpy(string, trim_str(string));
                strcpy(orderies[count].name, string);
                break;
            case 1:
                strcpy(string, trim_str(string));
                orderies[count].quantity = atoi(string);
                break;
            case 2:
                strcpy(string, trim_str(string));
                orderies[count].price = atof(string);
                break;
            case 3:
                strcpy(string, trim_str(string));
                strcpy(orderies[count].state, string);
                break;
            }
            string = strtok(NULL, ",");
            //strcpy(string, trim_str(string));
            cols++;
        }
        count++;
      }
  return count;
}

int read_tax(char* file, struct salesTax* orderies)
{

    FILE *taxList;

    char line[256], *string;

    int count = 0, cols = 0;
    if((taxList = fopen(file, "r")) == NULL)
    {
        printf("No File\n");
        exit(1);
    }
    while(fgets(line, 256, taxList))
    {
      strcpy(line, trim_str(line));
        cols = 0;
        string = strtok(line, ",");
        while (string)
        {
            switch (cols)
            {
            case 0:
                strcpy(string, trim_str(string));
                strcpy(taxlist[count].state, string);
                break;
            case 1:
                strcpy(string, trim_str(string));
                strcpy(taxlist[count].st_abr, string);
                break;
            case 2:
                strcpy(string, trim_str(string));
                taxlist[count].sales_tax = atof(string);
                break;
            }
            string = strtok(NULL, ",");
            cols++;
        }
        count++;
    }
    return count;
}

int main(int argc, char *argv[]) {
FILE *invoiceFinal;
char orders[256],taxes[256],invoice[256];
int order_count, tax_count;
int a,b,x,y,z,test;
float total_tax,grandTotal;

    if (argc < 4){
      
        strcpy(orders, "order.txt");
        strcpy(taxes, "tax_rate.txt");
        strcpy(invoice, "invoice.txt");
    }
    else{
        strcpy(orders, argv[1]);
        strcpy(taxes, argv[2]);
        strcpy(invoice, argv[3]);
      }

      order_count = read_order(orders,orderies);
      tax_count = read_tax(taxes,taxlist);
      //printf("%d \n", 1);
      for(x = 0; x < order_count;x++){
        //printf("%d \n", order_count);
        for(y = 0; y < tax_count;y++){
          
          test = strcmp(orderies[x].state,taxlist[y].st_abr);
          
          if(test == 0){
            // printf("%f \n", orderies[x].price);
            // printf("%f \n", taxlist[y].sales_tax);
            // printf("%s \n", orderies[x].name);
            gcvt(orderies[x].quantity*orderies[x].price * taxlist[y].sales_tax*0.01,3,invoicelist[x].tax);
            gcvt((orderies[x].quantity*orderies[x].price * taxlist[y].sales_tax*0.01) + (orderies[x].price*orderies[x].quantity),5,invoicelist[x].subtotal);
          }
        }
        //printf("%s \n", invoicelist[x].tax);
        //printf("%s \n", invoicelist[x].subtotal);
      }
      if((invoiceFinal = fopen("invoice.txt", "w")) == NULL)
    {
        printf("No File\n");
        exit(1);
    }
    fprintf(invoiceFinal, "%-25s%-10s%-10s%-10s%-10s%-10s\n","Product", "Price", "Quantity", "State", "Tax", "Subtotal");
    fprintf(invoiceFinal, "--------------------------------------------------------------------------------------\n");
    for(z = 0; z < order_count;z++){
    fprintf(invoiceFinal, "%-25s%-10.2f%-10d%-10s%-10.5s%-10.5s\n", 
            orderies[z].name, orderies[z].price, orderies[z].quantity, orderies[z].state,invoicelist[z].tax, invoicelist[z].subtotal);
    }
  for(a = 0; a < order_count; a++){
    total_tax+= atof(invoicelist[a].tax);
    grandTotal+= atof(invoicelist[a].subtotal);
  }
  fprintf(invoiceFinal,"Total Tax Due: %.2f\n",total_tax);
  fprintf(invoiceFinal,"Grand Total: %.2f\n",grandTotal);
  
      //printf("%s \n", &invoice[0]);
      // printf("%s \n", orderies[0].name);
      // printf("%d \n", orderies[0].quantity);
      // printf("%f \n", orderies[0].price);
      // printf("%s \n", orderies[0].state);
      // printf("%s \n", orderies[1].name);
      // printf("%d \n", orderies[1].quantity);
      // printf("%f \n", orderies[1].price);
      // printf("%s \n", orderies[1].state);
      // // printf("%s \n", taxlist[1].state);
      // printf("%s \n", taxlist[30].st_abr);
      // printf("%d\n",strcmp(orderies[1].state,taxlist[30].st_abr));
      //printf("%f \n", taxlist[1].sales_tax);
  fclose(invoiceFinal);
  return 0;
}