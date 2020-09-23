#include "sym_check.h"
#include "stdlib.h"
void sym_check(int* pos, table_t* t) {
    for (int i = 0; i < 4; i++) {
        rotate(pos);
        if (table_search(t,pos) != NULL) {
            return;
        }
    } 
    flip(pos);
    if (table_search(t,pos) != NULL) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        rotate(pos);
        if (table_search(t,pos) != NULL) {
            return;
        }
    } 
    flip(pos);
    if (table_search(t,pos) != NULL) {
        return;
    }
}
