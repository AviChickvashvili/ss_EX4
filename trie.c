#include "trie.h" 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    bool isWord;
    int count;
    struct node *parant;
    struct node *children[26];
    char ch;
};

struct node *buildTrie()
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->isWord = false;
    temp->count = 0;
    temp->ch = '\0';
    for (int i = 0; i < 26; i++)
    {
        temp->children[i] = NULL;
    }
    return temp;
}

typedef struct node node_t;

void insertNode(node_t *trieTree, char *mila)
{
    int key = 'a';
    int n = strlen(mila);
    node_t *currentNode = trieTree;

    for (int i = 0; i < n; i++)
    {
        int ans = *mila - key;
        if (currentNode->children[ans] == NULL)
        {
            currentNode->children[ans] = buildTrie();
        }

        currentNode = currentNode->children[ans];
        currentNode->ch = *mila;
        mila++;
    }
    currentNode->count = currentNode->count + 1; //////
    currentNode->isWord = true;
}

void printReverseTrie(node_t *trieTree, char *mila, int index)
{

    if (trieTree->isWord == true)
    {

        mila[index] = 0;
        printf("%s %d\n", mila , trieTree->count);
    }

    if (trieTree == NULL)
    {
        printf("the tree is empty");
        return;
    }
    for (int i = 25; i >= 0; i--)
    {
        int key = 'a';

        if (trieTree->children[i] != NULL)
        {
            mila[index] = key + i;
            node_t *curr = trieTree->children[i];
            index = index + 1;
            printReverseTrie(curr, mila, index);
            index = index - 1;
        }
    }
}
void printByorder(node_t *temp, char *mila, int index)
{

    if (temp == NULL)
    {
        printf("the tree is empty");
        return;
    }
    if (temp->isWord == true)
    {
        mila[index] = 0;
        printf("%s %d\n", mila , temp->count);
    }

    for (int i = 0; i < 26; i++)
    {
        int key = 'a';

        if (temp->children[i] != NULL)
        {
            mila[index] = key + i;
            node_t *curr = temp->children[i];
            index = index + 1;
            printByorder(curr, mila, index);
            index = index - 1;
        }
    }
}

void freeMem(node_t *root)
{

    for (int i = 0; i < 26; i++)
    {
        if ((root->children[i]))
        {
            freeMem(root->children[i]);
        }
    }
    free(root);
}