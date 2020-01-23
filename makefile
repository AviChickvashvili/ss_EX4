all: frequency

frequency: trie.o main.o
		gcc -Wall -g -o frequency trie.o main.o
trie.o: trie.c trie.h
		gcc -Wall -g -fPIC -c trie.c
main.o: main.c trie.h
		gcc -Wall -g -fPIC -c main.c

.PHONY: clean all

clean:	
		rm -f *.o frequency
