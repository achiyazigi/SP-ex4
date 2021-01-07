//
// Created by achiyazigi on 06/01/2021.
//

#ifndef EX4_TRIE_H
#define EX4_TRIE_H

#endif //EX4_TRIE_H

#ifndef NUM_LETTERS
#define NUM_LETTERS ((int)26)
#endif

typedef struct node{
    char letter;
    long unsigned int count;
    struct node *children[NUM_LETTERS];
}node;

typedef struct Trie{
    node *root;
    int longest_word;
}Trie;

typedef struct tuple{
    char *word;
    long unsigned int count;
}tuple;

void print_results(Trie *t, int flag);
node *add_char(Trie *t);
void build_Trie(Trie *t);
node *new_node(char letter, long unsigned int count, node *children[NUM_LETTERS]);
void kill(Trie *t);
