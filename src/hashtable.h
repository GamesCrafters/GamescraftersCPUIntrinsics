//#include "ttt.h"
#ifndef HASHTABLE_H
#define HASHTABLE_H
typedef struct DataItem {
    int* key;
    int data;
} item_t;
typedef struct hashTable {
    item_t* table;
    int size;
} table_t;
void table_init(table_t* t,int size);
int table_search(table_t* t, int* state);
void table_insert(table_t* t, int* state, int data);
void table_free(table_t* t);
#endif

