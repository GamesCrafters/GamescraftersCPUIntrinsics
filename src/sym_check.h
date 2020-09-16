#ifdef SIMD
#include "4x4SIMD.h"
#else 
#include "4x4Naive.h"
void sym_check(int* position,table_t* t);