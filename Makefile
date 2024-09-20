WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror 
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --show-leak-kinds=all --verbose

TESTFALGS = -DTEST_DIVISIONS
SRCS = main.c a4.c
OBJS = $(SRCS:%.c=%.o)

a4: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o a4

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: a4
	$(VAL) ./a4 "open 1"

t: a4 
	$(VAL) ./a4

clean: # remove all machine generated files
	rm -f a4 *.o output? *~


