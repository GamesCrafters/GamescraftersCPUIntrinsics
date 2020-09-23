#include "sym_check.h"
#include "hashtable.h"
typedef struct move_list{ 
    int count;
    int* moves;
} move_list_t;
int* doMove(int* start, int move,table_t* t);
move_list_t* generateMoves(int* start);
int primitiveValue(int* start);
int hash(int* start);