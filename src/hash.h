#ifndef HASH_H
#define HASH_H
unsigned hash_count(int spaces, int max_X, int max_O);
unsigned hash(int* board);
void init_hash(int size); //Assumes the size of the board is the largest object
void free_hash(void);
#endif
