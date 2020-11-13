#include <stdlib.h>
#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#endif
#include "solver.h"
// 0 is not primitive, 1 is prim lose, 2 is lose, 3 is win, 4 is tie, 6 is not 
#ifndef _OPENMP
void solver(int* start,table_t* t) {
    char isTie = 0;
    char isPrim = primitiveValue(start);
    if ((isPrim == 1 || isPrim == 4) && table_search(t,start) == -1) {
        table_insert(t,start,isPrim);
        free(start);
        return;
    }
    move_list_t* move_list = generateMoves(start);
    int* new_pos;
    char data;
    for (int i = 0; i < move_list->count; i++) {
        new_pos = doMove(start,move_list->moves[i],t);
        data = table_search(t,new_pos);
        if (data == 0) {
            solver(new_pos,t);
            data = table_search(t,new_pos);
        }
        if (data == 3) {
            table_insert(t,start,2);
        } else if (data == 4 || data == 5) {
            isTie = 1;
        }
    }
    free_move_list_t(move_list); 
    data = table_search(t,start);
    if (data == 0) {
        if (isTie) {
            table_insert(t,start,5);
        } else {
            table_insert(t,start,3);
        }
    }
    free(start);
}
#else
void solver(int* start,table_t* t) {
    char isTie = 0;
    char isPrim = primitiveValue(start);
    if ((isPrim == 1 || isPrim == 4) && table_search(t,start) == -1) {
        table_insert(t,start,isPrim);
        free(start);
        return;
    }
    move_list_t* move_list = generateMoves(start);
    int* new_pos;
    char data;
    int nth;
    omp_set_num_threads(move_list->count);
    #pragma omp parallel
    {
            nth = omp_get_thread_num();
            new_pos = doMove(start,move_list->moves[nth],t);
            data = table_search(t,new_pos);
            if (data == 0) {
                solver(new_pos,t);
                data = table_search(t,new_pos);
            }
            if (data == 3) {
                table_insert(t,start,2);
                #pragma omp cancel parallel
         } else if (data == 4 || data == 5) {
             isTie = 1;
         }
    }
    free_move_list_t(move_list); 
    data = table_search(t,start);
    if (data == 0) {
        if (isTie) {
            table_insert(t,start,5);
        }  else {
            table_insert(t,start,3);
        }
    }
    free(start);
}
#endif