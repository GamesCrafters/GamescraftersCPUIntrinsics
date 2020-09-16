#include <stdlib.h>
#include "../struct/hashtable.c"
extern pos doMove(pos position, move move,table_t* t);
extern move_list generateMoves(pos position);
extern int primitiveValue(pos position);
// 0 is not primitive, 1 is prim lose, 2 is lose, 3 is win, 4 is tie
void solver(pos start,table_t* t) {
    int isPrim = primitiveValue(start);
    if ( isPrim== 1) {
        insert(t,start,isPrim);
        return;
    }
    move_list = generateMoves(start);
    for (int i = 0; i < move_list->size; i++) {
        new_pos = doMove(start,move_list->list[i]);
        int data = search(t,new_pos);
        if (data == NULL) {
            solver(new_post,t);
        } 
        if (data == 3) {
            insert(t,start,2);
        }
    }
    if (!search(t,start)) {
        insert(t,start,3);
    }
}