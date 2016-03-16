#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

void trie_constructor(struct trie *this)
{
	size_t i;

	for (i = 0; i < 0x80; ++i) {
		this->next[i] = NULL;
	}
}

void trie_destructor(struct trie *this)
{
	size_t i;

	if (this == NULL) {
		return;
	}

	for (i = 0; i < 0x80; ++i) {
		delete_trie(this->next[i]);
	}
}

struct trie *new_trie()
{
	struct trie *this;

	this = malloc(sizeof(struct trie));

	if (this == NULL) {
		fprintf(stderr,
		        "%s:%d: malloc returned NULL\n",
		        __FILE__,
		        __LINE__ - 3);
		exit(EXIT_FAILURE);
	}

	trie_constructor(this);

	return this;
}

void delete_trie(struct trie *this)
{
	if (this == NULL) {
		return;
	}

	trie_destructor(this);
	free(this);
}

void trie_add_word(struct trie *this, const char *word)
{
	if (this->next[(size_t)*word] == NULL) {
		this->next[(size_t)*word] = new_trie();
	}
	
	if (*word == '\0') {
		return;
	}

	trie_add_word(this->next[(size_t)*word], word + 1);
}

int trie_has_word(struct trie *this, const char *word)
{
	if (this->next[(size_t)*word] == NULL) {
		return 0;
	}
	
	if (*word == '\0') {
		return 1;
	}

	return trie_has_word(this->next[(size_t)*word], word + 1);
}

static void _trie_print_helper(struct trie *this, FILE *fp, size_t level)
{
	size_t i, j;

	for (i = 0; i < 0x80; ++i) {
		if (this->next[i] != NULL) {
			for (j = 0; j < level; ++j) {
				fputc(' ', fp);
			}

			if (i == 0) {
				fputs("(null)\n", fp);
			} else {
				fprintf(fp, "%c\n", (char)i);
			}

			_trie_print_helper(this->next[i], fp, level + 1);
		}
	}
}

void trie_print(struct trie *this, FILE *fp)
{
	_trie_print_helper(this, fp, 0);
}
