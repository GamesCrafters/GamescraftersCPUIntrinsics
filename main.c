#include <stdlib.h>
#include <math.h>
int main(int argc, char** argv) {
    int* board = calloc(16,sizeof(int));
    table_t* t;
    init_table(t,pow(3,17));
    solver(board,t);
    return 0;
}