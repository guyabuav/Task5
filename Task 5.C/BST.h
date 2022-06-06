#ifndef _BST_ADT_H
#define _BST_ADT_H
#include <stdbool.h>
typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;

#endif // !_BST_ADT_H

void initBST(BST* bst);
void insertBST(BST* bst, int value);
void printTreeInorder(BST* bst);
void destroyBST(BST* bst);
int findIndexNFromLast(BST* bst, int N);
int mid(TreeNode* node);
int foo(BST* bst, int middle, int N);
bool CheckLeafLevel(BST* bst, int level, int* leaflevel);
int sameHeightLeaves(BST* bst);
int CountRoots(BST* bst);
int CountRoots2(TreeNode* node);
int countLeftPath(BST* bst);