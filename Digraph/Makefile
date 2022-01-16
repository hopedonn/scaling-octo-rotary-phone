CC=g++
CFLAGS=-pedantic -Wall -Wextra -g

digraph_analyzer: digraph_analyzer.o
	$(CC) -o digraph_analyzer digraph_analyzer.o

digraph_analyzer.o: digraph_analyzer.cpp digraph_functions.h
	$(CC) $(CFLAGS) -c digraph_analyzer.cpp 

clean:
	rm -f *.o digraph_analyzer