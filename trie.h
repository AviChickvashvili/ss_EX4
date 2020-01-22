#ifndef _TRIE_H_
#define _TRIE_H_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct node node_t;

node_t *buildTrie();
void insertNode(node_t *trieTree, char *mila);
void printReverseTrie(node_t *trieTree, char *mila, int index);
void printByorder(node_t *temp, char *mila, int index);
void freeMem(node_t *root);



#endif