#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solver.h"
#include "hashtable.h"
#include "hash.h"

int main(int argc, char** argv) {
    int* board = malloc(sizeof(int) * 16);
    for (int i = 0; i < 16; i++) {
        *(board+i) = 0;
    }
    table_t* t = table_init(16,8,8);
    solver(board,t);
    table_free(t);
    return 0;
}
