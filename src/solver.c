#include <stdlib.h>
#include "solver.h"
// 0 is not primitive, 1 is prim lose, 2 is lose, 3 is win, 4 is tie
void solver(int* start,table_t* t) {
    int isTie = 0;
    int isPrim = primitiveValue(start);
    if ((isPrim == 1 || isPrim == 4) && table_search(t,start) == -1) {
        table_insert(t,start,isPrim);
        return;
    }
    move_list_t* move_list = generateMoves(start);
    int* new_pos;
    int data;
    for (int i = 0; i < move_list->count; i++) {
        new_pos = doMove(start,move_list->moves[i],t);
        data = table_search(t,new_pos);
        if (data == -1) {
            solver(new_pos,t);
            data = table_search(t,new_pos);
        }
        if (data == 1 || data == 2) {
            table_insert(t,new_pos,3);
        } else if (data == 4) {
            isTie = 1;
        }
    } 
    data = table_search(t,start);
    if (data == -1 && isTie) {
        table_insert(t,start,4);
    } else {
        table_insert(t,start,3);
    }
}