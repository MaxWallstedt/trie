#include <stdio.h>
#include <assert.h>
#include "trie.h"

int main()
{
	struct trie *t;

	t = new_trie();

	assert(!trie_has_word(t, ""));
	assert(!trie_has_word(t, "hej"));
	assert(!trie_has_word(t, "hejsan"));

	fputs("trie 1:\n", stdout);
	trie_print(t, stdout);

	trie_add_word(t, "hejsan");

	assert(!trie_has_word(t, ""));
	assert(!trie_has_word(t, "hej"));
	assert(trie_has_word(t, "hejsan"));

	fputs("trie 2:\n", stdout);
	trie_print(t, stdout);

	trie_add_word(t, "hej");

	assert(!trie_has_word(t, ""));
	assert(trie_has_word(t, "hej"));
	assert(trie_has_word(t, "hejsan"));

	fputs("trie 3:\n", stdout);
	trie_print(t, stdout);

	trie_add_word(t, "");

	assert(trie_has_word(t, ""));
	assert(trie_has_word(t, "hej"));
	assert(trie_has_word(t, "hejsan"));

	fputs("trie 4:\n", stdout);
	trie_print(t, stdout);

	delete_trie(t);

	return 0;
}
