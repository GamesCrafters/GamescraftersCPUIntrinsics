#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "hash.h"
//With rearranger hash no collisions are possible
void table_init(table_t** t, long size,int boardsize) {
    table_t* table = *t;
    table = malloc(sizeof(table_t));
    table->size = size;
    table->table = malloc(sizeof(int)* table->size);
    for (long i = 0; i < table->size; i++) {
        table->table[i] = -1;
    }
}

int table_search(table_t* table,int* state,int boardsize) {
    long hashIndex = hash(state,boardsize); 
    return table->table[hashIndex];
    /*
    while(table->table[hashIndex].key != NULL) {
        if (table->table[hashIndex].key == state) {
            return table->table[hashIndex].data;
        }
        hashIndex++;
        hashIndex %= table->size;
    }
    return -1; */
}
void table_insert(table_t* table, int* state, int boardsize, int data) {
    long hashIndex = hash(state,boardsize);
    table->table[hashIndex] = data;
    /*
    while(table->table[hashIndex].key != NULL) {
        hashIndex++;
        hashIndex %= table->size;
    }
    table->table[hashIndex].key = state;
    table->table[hashIndex].data = data; */
}
void table_free(table_t* table) {
    free(table->table);
    free(table);
}
