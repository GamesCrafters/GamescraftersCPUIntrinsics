#ifndef HASHTABLE_H
#define HASHTABLE_H
typedef struct hashTable {
    char* table;
    unsigned size;
} table_t;
table_t* table_init(int boardsize, int max_X, int max_O);
char table_search(table_t* t, int* state);
void table_insert(table_t* t, int* state, char data);
void table_free(table_t* t);
#endif

