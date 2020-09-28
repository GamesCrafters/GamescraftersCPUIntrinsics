#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "hash.h"
//With rearranger hash no collisions are possible
void table_init(table_t** t,int size,int boardsize) {
    table_t* table = *t;
    int* hash_table = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
	*(hash_table+i) = -1;
    }
    table = malloc(sizeof(table_t));
    table->size = size;
    //table->table = malloc(sizeof(int)* table->size);
    table->table = hash_table;
    /*
    for (int i = 0; i < table->size; i++) {
        table->table[i] = -1;
    }*/
}

int table_search(table_t* table,int* state,int boardsize) {
    int hashIndex = hash(state,boardsize); 
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
    int hashIndex = hash(state,boardsize);
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
