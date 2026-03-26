#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXIMUM 100

typedef struct {
    char id[20];
    char name[50];
    int quantity;
    double price;
} Item;


Item items[MAXIMUM];
int item_count = 0;

int find_item(char *id) {
    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].id, id) == 0) return i;
    }
    return -1;
}

int main() {
    char input[200];

    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "---") == 0) break;

        char *token = strtok(input, "#");

        if (strcmp(token, "receive") == 0) {
            char *id = strtok(NULL, "#");
            char *name = strtok(NULL, "#");
            char *qty_str = strtok(NULL, "#");
            char *price_str = strtok(NULL, "#");

            int qty = atoi(qty_str);
            double price = atof(price_str);

            strcpy(items[item_count].id, id);
            strcpy(items[item_count].name, name);
            items[item_count].quantity = qty;
            items[item_count].price = price;

            item_count++;
        }

        else if (strcmp(token, "report") == 0) {
            for (int i = 0; i < item_count; i++) {
                printf("%s|%s|%d|%.1f\n",
                       items[i].id,
                       items[i].name,
                       items[i].quantity,
                       items[i].price);
            }
        }
    }

    while (2) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "---") == 0) break;

        char *token = strtok(input, "#");

        if (strcmp(token, "receive") == 0) {
            char *id = strtok(NULL, "#");
            char *name = strtok(NULL, "#");
            char *qty_str = strtok(NULL, "#");
            char *price_str = strtok(NULL, "#");

            int qty = atoi(qty_str);
            double price = atof(price_str);

            strcpy(items[item_count].id, id);
            strcpy(items[item_count].name, name);
            items[item_count].quantity = qty;
            items[item_count].price = price;

            item_count++;
        }

        else if (strcmp(token, "ship")==0){
            char *id = strtok(NULL, "#");
            char *qty_str = strtok(NULL, "#");
            
            int qty = atoi(qty_str);
            int idx = find_item(id);
            
            items[idx].quantity -= qty;
        }

        else if (strcmp(token, "restock")==0){
            char *id = strtok(NULL, "#");
            char *qty_str = strtok(NULL, "#");
            
            int qty = atoi(qty_str);
            int idx = find_item(id);
            
            items[idx].quantity += qty;
        }

        else if (strcmp(token, "report") == 0) {
            for (int i = 0; i < item_count; i++) {
                printf("%s|%s|%d|%.1f\n",
                       items[i].id,
                       items[i].name,
                       items[i].quantity,
                       items[i].price);
            }
        }
    }

     while (3) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "---") == 0) break;

        char *token = strtok(input, "#");

        if (strcmp(token, "receive") == 0) {
            char *id = strtok(NULL, "#");
            char *name = strtok(NULL, "#");
            char *qty_str = strtok(NULL, "#");
            char *price_str = strtok(NULL, "#");

            int qty = atoi(qty_str);
            double price = atof(price_str);

            strcpy(items[item_count].id, id);
            strcpy(items[item_count].name, name);
            items[item_count].quantity = qty;
            items[item_count].price = price;

            item_count++;
        }

        else if (strcmp(token, "ship")==0){
            char *id = strtok(NULL, "#");
            char *qty_str = strtok(NULL, "#");
            
            int qty = atoi(qty_str);
            int idx = find_item(id);
            
            items[idx].quantity -= qty;
        }

        else if (strcmp(token, "restock")==0){
            char *id = strtok(NULL, "#");
            char *qty_str = strtok(NULL, "#");
            
            int qty = atoi(qty_str);
            int idx = find_item(id);
            
            items[idx].quantity += qty;
        }
        else if (strcmp(token, "atoi")==0){
            char *id = strtok(NULL, "#");
            char *qty_str = strtok(NULL, "#");
            
            if(!id || !qty_str);
            int qty = atoi(qty_str);
            int idx = find_item(id);
            
            if (qty <= 0);
            if (idx == -1);
            if (items[idx].quantity < qty) 

            items[idx].quantity -= qty;
        }


        else if (strcmp(token, "report") == 0) {
            for (int i = 0; i < item_count; i++) {
                printf("%s|%s|%d|%.1f\n",
                       items[i].id,
                       items[i].name,
                       items[i].quantity,
                       items[i].price);
            }
        }
    }

    return 0;
}