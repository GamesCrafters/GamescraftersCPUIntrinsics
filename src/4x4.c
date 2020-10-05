#include "4x4.h"
#ifdef SIMD 
#include <x86intrin.h>
static void transpose(int* position) {
	
	__m128 r0,r1,r2,r3;
	__m128 t0,t1,t2,t3;
		
	r0 = _mm_castsi128_ps(_mm_loadu_si128(&position[0*4]));
	r1 = _mm_castsi128_ps(_mm_loadu_si128(&position[1*4]));
	r2 = _mm_castsi128_ps(_mm_loadu_si128(&position[2*4]));
	r3 = _mm_castsi128_ps(_mm_loadu_si128(&position[3*4]));

	t0 = _mm_unpacklo_ps(r0,r1);
	t1 = _mm_unpackhi_ps(r0,r1);
	t2 = _mm_unpacklo_ps(r2,r3);
	t3 = _mm_unpackhi_ps(r2,r3);

	r0 = _mm_shuffle_ps(t0,t2,0x44);
	r1 = _mm_shuffle_ps(t0,t2,0xEE);
	r2 = _mm_shuffle_ps(t1,t3,0x44);
	r3 = _mm_shuffle_ps(t1,t3,0xEE);

	_mm_storeu_si128(&position[0*4],_mm_castps_si128(r0));
	_mm_storeu_si128(&position[1*4],_mm_castps_si128(r1));
	_mm_storeu_si128(&position[2*4],_mm_castps_si128(r2));
	_mm_storeu_si128(&position[3*4],_mm_castps_si128(r3));
}
void flip(int* position) {
	__m128i r0,r1,r2,r3;
	
	r0 = _mm_load_si128(&position[0*4]);
	r1 = _mm_load_si128(&position[1*4]);
	r2 = _mm_load_si128(&position[2*4]);
	r3 = _mm_load_si128(&position[3*4]);

	_mm_store_si128(&position[0*4],r3);
	_mm_store_si128(&position[1*4],r2);
	_mm_store_si128(&position[2*4],r1);
	_mm_store_si128(&position[3*4],r0);
}
void rotate(int* position) {
	flip(position);
	transpose(position);
}
void arr_copy(int* dst, int* src) {
	_mm_store_si128(&dst[0*4],_mm_load_si128(&src[0*4]));
	_mm_store_si128(&dst[1*4],_mm_load_si128(&src[1*4]));
	_mm_store_si128(&dst[2*4],_mm_load_si128(&src[2*4]));
	_mm_store_si128(&dst[3*4],_mm_load_si128(&src[3*4]));
}
#else
static void transpose(int* position) {
    int temp;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            temp = *(position+(4*i)+j);
            *(position+(4*i)+j) = *(position+(4*j)+i);
            *(position+(4*j)+i) = temp;
        }
    }
}
void flip(int* position) {
	int temp;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			temp = *(position+(4*i)+j);
			*(position+(4*i)+j) = *(position+(4*(3-i))+j);
			*(position+(4*(3-i))+j) = temp;
		}
	}
}
void rotate(int* position) {
	flip(position);
	transpose(position);
}
void arr_copy(int* dst, int* src) {
	for (int i = 0; i < 16; i++) {
		*(dst+i) = *(src+i);
	}
}
#endif