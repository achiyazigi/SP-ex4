//
// Created by achiyazigi on 06/01/2021.
//a tool to create trie of lowercase letters
//uppercase turn to lowercase, other chars are ignored
//

#include "Trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//allocate memory for a new node
node *new_node(char letter, long unsigned int count, node *children[NUM_LETTERS]){
    node *new_n = (node*)calloc(1, sizeof(node));
    new_n->letter = letter;
    new_n->count = count;
    if(children)
        memcpy(new_n->children, children, NUM_LETTERS);
    return new_n;
}

//give the next letter in lower case or space (ignores other chars)
char next_char(){
    char c = getchar();
    while(c!=EOF && c!= ' ' && c!='\n' &&(c <'A' || c > 'z' || (c>'Z'&&c<'a')))
        c = getchar();
    c = tolower(c);
    return c;
}

//calculate the next word
node *add_char(Trie *t){
    int i = 0;
    char c = next_char();
    while(c == ' ')
        c = next_char();
    node *cur = t->root;
    node *temp = cur;
    while(c!= ' ' && c != '\n' && (cur = cur->children[c-'a'])){
        i++;
        temp = cur;
        c = next_char();
    }
    cur = temp;
    while(c != ' ' && c!= '\n' && c!= EOF){
        cur->children[c-'a'] = new_node(c,0,NULL);
        i++;
        cur = cur->children[c-'a'];
        c = next_char();
    }
    cur->count++;
    if(i>t->longest_word){
        t->longest_word = i;
    }
    return cur;
}

//build the trie
void build_Trie(Trie *t){
    while(getchar() != EOF){
        fseek(stdin, -1, SEEK_CUR);
        add_char(t);
    }
}

//in use from print results.
void print_result(node *pNode, char *word, int flag) {
    if(pNode) {
        size_t len = strlen(word);
        word[len] = pNode->letter;
        if (pNode->count) {
            printf("%s %ld\n", word, pNode->count);
        }
        int j;
        for (int i = 0; i <26; ++i) {
            j = i;
            if(flag){
                j = 25 - i;
            }
            if(pNode->children[j])
                print_result(pNode->children[j], word, flag);
        }
        len = strlen(word);
        if(len)
            word[len-1] = 0;

    }
}

//print the data from trie t
void print_results(Trie *t, int flag){
    char *word = (char*)calloc(1, t->longest_word * sizeof(char)+2);
    print_result(t->root, word, flag);
    free(word);
}

//free the memory of a node
void kill_node(node *n){
    if(n) {
        for (int i = 0; i <26; ++i) {
            if(n->children[i])
                kill_node(n->children[i]);
        }
        free(n);
    }
}

//free the memory of the trie
void kill(Trie *t){
    kill_node(t->root);
}

