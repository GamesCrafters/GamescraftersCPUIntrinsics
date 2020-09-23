#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solver.h"
#include "hashtable.h"
#include "hash.h"
int main(int argc, char** argv) {
    int* board = calloc(16,sizeof(int));
    table_t* t;
    printf("Initing table\n");
    table_init(&t,hash_count(16,8,8),16);
    printf("Starting solver\n");
    solver(board,t,16);
    printf("Solver completed\n");
    table_free(t);
    return 0;
}
