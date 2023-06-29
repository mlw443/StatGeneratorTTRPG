WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = main.c statGen.c
OBJS = $(SRCS:%.c=%.o)

TESTFLAGS := -DMAIN 

# run in a normal make command
statGen: clean $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o statGen
	./statGen

# use if you want to see the sum of each 
# row, column, and diagnal
sum: TESTFLAGS += -DDEBUG_SUM
sum: statGen

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c 

clean: # remove all machine generated files
	rm -f statGen *.o output?
