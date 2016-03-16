CC=gcc
CFLAGS=-g -pedantic -Wall -Wextra -Werror

all: test_trie

test_trie: test_trie.o trie.o
	$(CC) $(CFLAGS) -o test_trie test_trie.o trie.o

test_trie.o: test_trie.c trie.h
	$(CC) -c $(CFLAGS) test_trie.c

trie.o: trie.c trie.h
	$(CC) -c $(CFLAGS) trie.c

clean:
	rm -f test_trie 2>&1 || :
	rm -f test_trie.o 2>&1 || :
	rm -f trie.o 2>&1 || :
