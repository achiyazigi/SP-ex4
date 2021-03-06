CC = gcc
FLAGS = -Wall
LD_FLAGS="-Wl,-R."
.PHONY: all clean mymaths mymathd

all:frequency

frequency:main.o Trie.o
	$(CC) $(FLAGS) -o $@ $^
main.o:main.c
	$(CC) $(FLAGS) -o $@ -c $^
Trie.o:Trie.c
	$(CC) $(FLAGS) -o $@ -c $^
clean:
	rm *.o frequency
