CC = gcc-9
CFLAGS = -g -mavx
DEFS = SIMD
DEPS = hashtable.h 4x4.h sym_check.h ttt.h solver.h 
OBJ = hashtable.o 4x4.o sym_check.o ttt.o solver.o 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -D $(DEFS) -c -o $@ $<
test: $(OBJ) main.c
	$(CC) $(CFLAGS) -o $@ $^