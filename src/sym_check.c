#include "sym_check.h"
#include "stdlib.h"
void sym_check(int* pos, table_t* t) {
    for (int i = 0; i < 4; i++) {
        rotate(pos);
        if (table_search(t,pos) != -1) {
            return;
        }
    } 
    flip(pos);
    if (table_search(t,pos) != -1) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        rotate(pos);
        if (table_search(t,pos) != -1) {
            return;
        }
    } 
    flip(pos);
    if (table_search(t,pos) != -1) {
        return;
    }
}
