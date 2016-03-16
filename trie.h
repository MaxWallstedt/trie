#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>

struct trie {
	struct trie *next[0x80];
};

void trie_constructor(struct trie *this);
void trie_destructor(struct trie *this);
struct trie *new_trie();
void delete_trie(struct trie *this);

void trie_add_word(struct trie *this, const char *word);
int trie_has_word(struct trie *this, const char *word);

void trie_print(struct trie *this, FILE *fp);

#endif
