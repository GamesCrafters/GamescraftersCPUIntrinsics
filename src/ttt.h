#include "sym_check.h"
#include "hashtable.h"
typedef struct move_list{ 
    int count;
    int* moves;
} move_list_t;
int* doMove(int* start, int move,table_t* t);
move_list_t* generateMoves(int* start);
char primitiveValue(int* start);
void free_move_list_t(move_list_t* ml);
