#define CRT_SECURE_NO_WARNINGS
#include "TreePrintLibrary.h"
#include "BST.h"
#include <stdbool.h>
#include <stdio.h>
#define AllocationCheck(temp) \
do { \
	if(temp == NULL) { \
		printf("allocation failed"); \
		exit(-1); \
	}  \
} while (0) \


void initBST(BST* bst) {
	
	bst->root = NULL; // Init new BST
	
	}


void insertBST(BST* bst, int value) {
	if (bst->root == NULL) { // if the tree is empty
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode)); // memory allocation for new node
		AllocationCheck(temp); // memory allocation by MACRO
		temp->element = value; // insert new value to the new node
		bst->root = temp;
		bst->root->left = NULL;
		bst->root->right = NULL;
		return;
	}
	else {
		if(value > bst->root->element) // arrange elements by order if binray tree
		return insertBST(&bst->root->right, value);
		if (value <= bst->root->element)
			return insertBST(&bst->root->left, value);
	}
}

void printTreeInorder(BST* bst) {
	if (bst->root != NULL) {
		printTreeInorder(&bst->root->left); // get to the left nodes
		printf("%d", bst->root->element);
		printTreeInorder(&bst->root->right); // get to the right nodes
	}
	
}

void destroyBST(BST* bst) {
	if (bst->root != NULL) {
		destroyBST(&bst->root->left); // get to the left nodes
		destroyBST(&bst->root->right); // get to the right nodes
		free(bst->root);
	}

}

int findIndexNFromLast(BST* bst, int N) {
	int all = CountRoots(bst);
	if (N > all || N < 1) { // if N is not in range
		printf("parameter N is not in range\n");
		return 0;
	}
	N = all - N + 1;
	int middle = mid(bst->root);
	int num = foo(bst, middle, N);
	return num;
	
	
	}
	

int mid(TreeNode* node) {
	int all = CountRoots2(node); // count all roots
	int right = CountRoots2(node->right); // count only roots of node.right
	int middle = all - right; // middle = roots of node.left
	return middle;
}
int foo(BST* bst, int middle, int N) {
	if (bst->root != NULL) {
		int num = 0;
		if (N == middle) { // if N = roots of node.left, return the current element.
			return bst->root->element;
		}
		if (middle < N) { // if N > middle, we need nodes from right part of the tree
			num = foo(&bst->root->right, middle + mid(bst->root->right) , N);
		}
		if (middle > N) { // in N < middle, we need nodes from left part of the tree
			num = foo(&bst->root->left, middle - mid(bst->root->left), N);
		}
		return num;
	}
	else {
		return NULL;
	}
}

bool CheckLeafLevel(BST* bst, int level, int* leaflevel) {
	if (bst->root == NULL) { // if the tree is empty, every path is equal
		return true;
	}
	if (bst->root->left == NULL && bst->root->right == NULL) { // if it is a leaf
		if (*leaflevel == 0) { // if its the first path we counting
			*leaflevel = level; // set first leaf level (we dont need this iteration because we have allready LEFT-PATH)
			return true;
		}
		return (level == *leaflevel); // if its not the first leaf, compare it to the last leaflevel we found.
	}
	return CheckLeafLevel(&bst->root->left, level + 1, leaflevel) && CheckLeafLevel(&bst->root->right, level + 1, leaflevel);
	// if this is not a leaf, check his left && right
	}


int sameHeightLeaves(BST* bst) {
	int* leaflevel = (int*)malloc(sizeof(int));
	*(leaflevel) = CountRoots2(bst->root->left) - 1; // count the nodes in left path in bst
	return (CheckLeafLevel(&bst->root, 0, leaflevel));
}

int CountRoots(BST* bst) { // count roots in bst by bst
	if (bst->root == NULL) {
		return 0;
	}
	return 1 + CountRoots(&bst->root->left) + CountRoots(&bst->root->right);
}

int CountRoots2(TreeNode* node) { // count roots in bst by treenode
	if (node == NULL ){
		return 0;
	}
	return 1 + CountRoots2(node->left) + CountRoots2(node->right);

}

int countLeftPath(BST* bst) { // count the left path of your bst.
	if (bst == NULL) {
		return 0;
	}
	return countLeftPath(bst->root->left) + 1;
}

