#include <stdlib.h>
#include <math.h>
#include "solver.h"
#include "hashtable.h"
int main(int argc, char** argv) {
    int* board = calloc(16,sizeof(int));
    table_t* t;
    table_init(t,pow(3,17));
    solver(board,t);
    table_free(t);
    return 0;
}