#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
static unsigned long long* factorial_table;
static int board_size;
void init_hash(int max) {
	board_size = max;
	factorial_table = malloc(sizeof(unsigned long long)*(max+1));
	*(factorial_table) = 1;
	for (int i = 1; i < board_size+1; i++) {
		*(factorial_table+i) = i * *(factorial_table+i-1);
	}
}
void free_hash(void) {
	free(factorial_table);
}

static unsigned long long factorial(int n) {
	return *(factorial_table+n);
}
static unsigned choose(int n, int k) {
	unsigned long long choose = factorial(n)/(factorial(n-k)*factorial(k));
	return (unsigned) choose;
	//return (int) factorial((long) n)/(factorial((long) (n-k))*factorial((long) k));
}
static unsigned count(int spaces, int X, int O) {
	return (choose(spaces,X+O) * choose(X+O,X));
}
static unsigned item_count(int* board, int item) {
	unsigned total = 0;
	for (int i = 0; i < board_size; i++) {
		if (*(board+i) == item) {
			total++;
		}
	}
	return total;
}
static unsigned hash_helper(int* board, int size, int X, int O) {
	if (((X == 0) && (O == 0)) || (size == X) || (size == O) || (size == 0)) {
		return 0;
	}
	if (*(board) == 0) {
		return hash_helper(board+1,size-1,X,O);
	} else if (*(board) == 1) {
		return (((X+O) == size ? 0 : count(size-1,X,O)) + hash_helper(board+1,size-1,X-1,O));
	} else {
		return (((X+O) == size ? 0 : count(size-1,X,O)) + (X == 0 ? 0 : count(size-1,X-1,O)) + hash_helper(board+1,size-1,X,O-1));
	}
}
unsigned hash_count(int spaces, int max_X, int max_O) {
	unsigned total = 0;
	int i = 0; 
	int j = 0;
	while (!(i > max_X)) {
		total +=  count(spaces,i,j);
		if (i == j) {
			i++;
		} else {
			j++;
		}
	}
	return total;
}
unsigned hash(int* board) {
	return hash_helper(board,board_size,item_count(board,1),item_count(board,2));
}
static int* createTestBoard() {
	int* board = malloc(sizeof(int)*board_size);
	for (int i = 0; i < board_size; i++) {
		if (i % 4 == 0) {
			*(board+i) = 1;
		} else if (i % 4 == 1) {
			*(board+i) = 2;
		} else {
			*(board+i) = 0;
		}
	}
	return board;
}
static void printBoard(int* board) {
	for (int i = 0; i < 4; i++) {
		printf("%u %u %u %u\n",*(board+(4*i)),*(board+(4*i)+1),*(board+(4*i)+2),*(board+(4*i)+3));
	}
}/*
int main() {
	int hashSize = hash_count(16,8,8);
	printf("Hash universe size %u\n",hashSize);
	int* board = createTestBoard();
	printBoard(board);
	int hashValue = hash(board,16);
	printf("%u\n",hashValue);
	return 0;
}*/
