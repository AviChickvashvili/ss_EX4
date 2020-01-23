#include "trie.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// struct node
// {
//     bool isWord;
//     int count;
//     struct node *parant;
//     struct node *children[26];
//     char ch;
// };

// struct node *buildTrie()
// {
//     struct node *temp = NULL;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->isWord = false;
//     temp->count = 0;
//     temp->ch = '\0';
//     for (int i = 0; i < 26; i++)
//     {
//         temp->children[i] = NULL;
//     }
//     return temp;
// }

// typedef struct node node_t;

// void insertNode(node_t *trieTree, char *mila)
// {
//     int key = 'a';
//     int n = strlen(mila);
//     node_t *currentNode = trieTree;

//     for (int i = 0; i < n; i++)
//     {
//         int ans = *mila - key;
//         if (currentNode->children[ans] == NULL)
//         {
//             currentNode->children[ans] = buildTrie();
//         }

//         currentNode = currentNode->children[ans];
//         currentNode->ch = *mila;
//         mila++;
//     }
//     currentNode->count = currentNode->count + 1; //////
//     currentNode->isWord = true;
// }

// void printReverseTrie(node_t *trieTree, char *mila, int index)
// {

//     if (trieTree->isWord == true)
//     {

//         mila[index] = 0;
//         printf("%s %d\n", mila , trieTree->count);
//     }

//     if (trieTree == NULL)
//     {
//         printf("the tree is empty");
//         return;
//     }
//     for (int i = 25; i >= 0; i--)
//     {
//         int key = 'a';

//         if (trieTree->children[i] != NULL)
//         {
//             mila[index] = key + i;
//             node_t *curr = trieTree->children[i];
//             index = index + 1;
//             printReverseTrie(curr, mila, index);
//             index = index - 1;
//         }
//     }
// }
// void printByorder(node_t *temp, char *mila, int index)
// {

//     if (temp == NULL)
//     {
//         printf("the tree is empty");
//         return;
//     }
//     if (temp->isWord == true)
//     {
//         mila[index] = 0;
//         printf("%s %d\n", mila , temp->count);
//     }

//     for (int i = 0; i < 26; i++)
//     {
//         int key = 'a';

//         if (temp->children[i] != NULL)
//         {
//             mila[index] = key + i;
//             node_t *curr = temp->children[i];
//             index = index + 1;
//             printByorder(curr, mila, index);
//             index = index - 1;
//         }
//     }
// }

// void freeMem(node_t *root)
// {

//     for (int i = 0; i < 26; i++)
//     {
//         if ((root->children[i]))
//         {
//             freeMem(root->children[i]);
//         }
//     }
//     free(root);
// }
int main(int argc, char *argv[])
{

    int i = 0;
    char *curr = (char *)malloc(sizeof(char));
    curr[i] = '\0';
    node_t *trieTree = buildTrie();
    char T = getchar();
    // T=tolower(T);
    i++;
    while (T != EOF)
    {
        while ((T != '\t' && T != '\n' && T != ' ' && T != EOF ) && ((T<='z'&&T>='a')||(T>='A'&&T<='Z'))  ) 
        {
            // insertNode(trieTree, word);
           
            curr = realloc(curr, (i) * sizeof(char));
            
            curr[i-1] = T;
            curr[i]='\0';
           
            T = getchar();
            //   T=tolower(T);
            i++;
        }
        int size = strlen(curr);
        for (int i = 0; i < size; i++)
        {
            curr[i] = tolower(curr[i]);
        }

        if (size != 0 && curr[size] != '\n' && curr[size] != ' ')
        {
            insertNode(trieTree, curr);
        }

        free(curr);
        T = getchar();
        //  T=tolower(T);
        if (T == EOF)
        {
            break;
        }
        else
        {
            T = tolower(T);
            curr = (char *)malloc(sizeof(char));
            i = 1;
            curr[i] = T;
        }
    }
    char *ans = (char *)malloc(sizeof(char));
    if (argc == 1)
    {
        int is = 0;
        printByorder(trieTree, ans, is);
    }
    if (argc == 2 && strcmp(argv[1], "r") == 0)
    {
        int isis = 0;
        printReverseTrie(trieTree, ans, isis);
    }

    freeMem(trieTree);
    free(ans);
    return 0;
}