CC = gcc
CFLAGS = -g -mavx -fopenmp
#DEFS = -D SIMD
DEPS = hashtable.h 4x4.h sym_check.h ttt.h solver.h hash.h 
OBJ = hashtable.o 4x4.o sym_check.o ttt.o solver.o hash.o
simd: DEFS = -D SIMD
simd: test


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(DEFS) -c -o $@ $<
test: $(OBJ) main.c
	$(CC) $(CFLAGS) -o $@ $^
.PHONY: clean
clean :
	rm test $(OBJ)
