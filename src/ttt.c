#include <string.h>
#include <stdlib.h>
#include "ttt.h"

static void reflect(int* board) {
    for (int i = 0; i < 16; i++) {
        if (*(board+i) == 1) {
            *(board+i) = 2;
        } else if (*(board+i) == 2) {
            *(board+i) = 1;
        }
    }
}
int* doMove(int* start, int move,table_t* t) {
    int* new = malloc(sizeof(int)*16);
    memcpy(new,start,16);
    *(new+move) = 1;
    reflect(new);
    sym_check(new, t);
    return new;
}
move_list_t* generateMoves(int* start) {
    int count = 0;
    move_list_t* mvlist = malloc(sizeof(move_list_t));
    for (int i = 0; i < 16; i++) {
        if (*(start+i) == 0) {
            count++;
        }
    }
    mvlist->count = count;
    mvlist->moves = malloc(sizeof(int)*count);
    int temp = 0;
    for (int i = 0; i < 16; i++) {
        if (*(start+i) == 0) {
            mvlist->moves[temp] = i;
            temp++;
        }
    }
    return mvlist;
}

int primitiveValue(int* start) {
    //may need to flip from 2 to 1
    int k;
    for (int i = 0; i < 4; i++) {
        k = 0;
        for (int j = 0; j < 4; j++) {
            if (*(start+i+(4*j)) == 2) {
                k++;
            }
        }
        if (k == 4) {
            return 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        k = 0;
        for (int j = 0; j < 4; j++) {
            if (*(start+j+(4*i)) == 2) {
                k++;
            }
        }
        if (k == 4) {
            return 1;
        }
    }
    k = 0;
    for (int i = 0; i < 4; i++) {
        if (*(start+i+(4*i)) == 2) {
            k++;
        }
    }
    if (k == 4) {
        return 1;
    }
    k = 0; 
    for (int i = 0; i < 4; i++) {
        if (*(start+(4-i)+(4*i)) == 2) {
            k++;
        }
    }
    if (k == 4) {
        return 1;
    }
    move_list_t* moves = generateMoves(start);
    if (moves->count == 0) {
        return 4;
    } 
    return 0;
}
int hash(int* pos) {
    int pow = 1;
    int hash = 0;
    for (int i = 0; i < 16; i++) {
        hash += *(pos+i) * pow;
        pow *= 3;
    }
    return hash;
}