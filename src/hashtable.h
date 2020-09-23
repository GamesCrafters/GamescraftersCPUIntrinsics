#ifndef HASHTABLE_H
#define HASHTABLE_H
typedef struct hashTable {
    int* table;
    long size;
} table_t;
void table_init(table_t** t,long size, int boardsize);
int table_search(table_t* t, int* state,int boardsize);
void table_insert(table_t* t, int* state, int boardsize,int data);
void table_free(table_t* t);
#endif

