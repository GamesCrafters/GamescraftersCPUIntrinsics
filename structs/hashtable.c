#include <stdlib.h>
//Oversized noncollision table.
typedef struct DataItem {
    int key;
    int data;
} item_t;
typedef struct hashTable {
    item_t* table;
    int size;
} table_t;

void init_table(table_t* table, int size) {
    table = malloc(sizeof(table_t));
    table->table = malloc(sizeof(item_t)*size);
    table->size = size;
}
extern int hash(int* state);

int search(item_t* table,int* state) {
    int hashIndex = hash(state);
    while(*(table+hashIndex) != NULL) {
        if (*(table+hashIndex)->key == state) {
            return *(table+hashIndex)->data;
        }
        hashIndex++;
        hashIndex %= table->size;
    }
    return NULL;
}
void insert(table_t* table, int* state, int data) {
    int hashIndex = hash(state);
    while(table->table[hashIndex] != NULL) {
        hashIndex++;
        hashIndex %= table->size;
    }
    table->table[hashIndex]->key = state;
    table->table[hashIndex]->data = data;
}
void free(table_t* table) {
    free(table->table);
    free(table);
}