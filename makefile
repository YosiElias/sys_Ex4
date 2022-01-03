CC = gcc
AR = ar
FLAGS = -Wall -g

make all: graph

# libgraph.so:graph.o
# 	$(CC) -shared -o libgraph.so graph.o
	
main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

# algo.o: algo.h graph.h algo.c  
# 	$(CC) $(FLAGS) -c algo.c

# graph: main.o libgraph.so
# 	$(CC) $(FLAGS) -o graph main.o ./libgraph.so

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c -lm

libgraph.a: graph.o
	$(AR) -rcs libgraph.a graph.o

graph: main.o libgraph.a 
	$(CC) $(FLAGS) -o graph main.o libgraph.a -lm

.PHONY: clean all
clean: 
	rm -f *.o *.so libgraph.a graph





