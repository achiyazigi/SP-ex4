#include <stdio.h>
#include "Trie.h"

int main(int argc, char *argv[]) {
    int flag = 0;
    Trie t;
    t.longest_word = 0;
    t.root = new_node(' ',0, NULL);
    if(!t.root){
        return -1;
    }
    build_Trie(&t);
    if(argc == 2 && *argv[1] == 'r'){
        flag = 1;
    }
    print_results(&t, flag);
    kill(&t);
    return 0;
}
