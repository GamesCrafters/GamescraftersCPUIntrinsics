#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
//Oversized noncollision table.
void table_init(table_t* table, int size) {
    table = malloc(sizeof(table_t));
    table->size = size;
    table->table = malloc(sizeof(item_t)*table->size);
    for (int i = 0; i < table->size; i++) {
        table->table[i].key = NULL;
    }
}

int table_search(table_t* table,int* state) {
    int hashIndex = hash(state);
    while(table->table[hashIndex].key != NULL) {
        if (table->table[hashIndex].key == state) {
            return table->table[hashIndex].data;
        }
        hashIndex++;
        hashIndex %= table->size;
    }
    return -1;
}
void table_insert(table_t* table, int* state, int data) {
    int hashIndex = hash(state);
    while(table->table[hashIndex].key != NULL) {
        hashIndex++;
        hashIndex %= table->size;
    }
    table->table[hashIndex].key = state;
    table->table[hashIndex].data = data;
}
void table_free(table_t* table) {
    free(table->table);
    free(table);
}