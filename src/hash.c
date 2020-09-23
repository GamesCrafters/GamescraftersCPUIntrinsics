#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
static long factorial(long n) {
	if ((n == 1) || (n==0)) {
		return 1;
	} else {
		return n*factorial(n-1);
	}
}
static int choose(int n, int k) {
	return factorial((long) n)/(factorial((long) (n-k))*factorial((long) k));
}
static int count(int spaces, int X, int O) {
	return (choose(spaces,X+O) * choose(X+O,X));
}
static int item_count(int* board, int size, int item) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		if (*(board+i) == item) {
			total++;
		}
	}
	return total;
}
static int hash_helper(int* board, int size, int X, int O) {
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
int hash_count(int spaces, int max_X, int max_O) {
	int total = 0;
	int i = 0; 
	int j = 0;
	while (!(i > max_X)) {
		total += count(spaces,i,j);
		printf("%u possible board, at i = %u, j = %u\n",total,i,j); 
		if (i == j) {
			i++;
		} else {
			j++;
		}
	}
	return total;
}
int hash(int* board, int size) {
	return hash_helper(board,size,item_count(board,size,1),item_count(board,size,2));
}
static int* createTestBoard() {
	int* board = malloc(sizeof(int)*16);
	for (int i = 0; i < 16; i++) {
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
}
int main() {
	int hashSize = hash_count(16,8,8);
	printf("Hash universe size %u\n",hashSize);
	int* board = createTestBoard();
	printBoard(board);
	int hashValue = hash(board,16);
	printf("%u\n",hashValue);
	return 0;
}
