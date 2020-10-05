#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "hash.h"
//With rearranger hash no collisions are possible
table_t* table_init(int boardsize,int max_X, int max_Y) {
    init_hash(boardsize);
    table_t* t = malloc(sizeof(table_t));
    t->size = hash_count(boardsize,max_X,max_Y);
    t->table = malloc(sizeof(char) * t->size);
    memset(t->table,-1,(size_t) t->size);
    return t;
    //table->table = malloc(sizeof(int)* table->size);
    /*
    for (int i = 0; i < table->size; i++) {
        table->table[i] = -1;
    }*/
}

char table_search(table_t* table,int* state) {
    unsigned hashIndex = hash(state); 
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
void table_insert(table_t* table, int* state, char data) {
    unsigned hashIndex = hash(state);
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
    free_hash();
    free(table->table);
    free(table);
}
