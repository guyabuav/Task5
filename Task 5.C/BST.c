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
	
	bst->root = NULL;
	
	}


void insertBST(BST* bst, int value) {
	if (bst->root == NULL) { // the tree is empty
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		AllocationCheck(temp);
		temp->element = value;
		bst->root = temp;
		bst->root->left = NULL;
		bst->root->right = NULL;
		return;
	}
	else {
		if(value > bst->root->element)
		return insertBST(&bst->root->right, value);
		if (value <= bst->root->element)
			return insertBST(&bst->root->left, value);
	}
}

void printTreeInorder(BST* bst) {
	if (bst->root != NULL) {
		printTreeInorder(&bst->root->left);
		printf("%d", bst->root->element);
		printTreeInorder(&bst->root->right);
	}
	
}

void destroyBST(BST* bst) {
	if (bst->root != NULL) {
		destroyBST(&bst->root->left);
		destroyBST(&bst->root->right);
		free(bst->root);
	}

}

int findIndexNFromLast(BST* bst, int N) {
	int all = CountRoots(bst);
	if (N > all || N < 1) {
		printf("parameter N is not in range");
		return 0;
	}
	N = all - N + 1;
	int middle = mid(bst->root);
	int num = foo(bst, middle, N);
	return num;
	
	
	}
	

int mid(TreeNode* node) {
	int all = CountRoots2(node);
	int right = CountRoots2(node->right);
	int middle = all - right;
	return middle;
}
int foo(BST* bst, int middle, int N) {
	if (bst->root != NULL) {
		int num = 0;
		if (N == middle) {
			return bst->root->element;
		}
		if (middle < N) {
			num = foo(&bst->root->right, middle + mid(bst->root->right) , N);
		}
		if (middle > N) {
			num = foo(&bst->root->left, middle - mid(bst->root->left), N);
		}
		return num;
	}
	else {
		return NULL;
	}
}

int sameHeightLeaves(BST* bst) {
	
	
	
}

int CountRoots(BST* bst) {
	if (bst->root == NULL) {
		return 0;
	}
	return 1 + CountRoots(&bst->root->left) + CountRoots(&bst->root->right);
}

int CountRoots2(TreeNode* node) {
	if (node == NULL ){
		return 0;
	}
	return 1 + CountRoots2(node->left) + CountRoots2(node->right);

}

int countLeftPath(BST* bst) {
	if (bst == NULL) {
		return 0;
	}
	return countLeftPath(bst->root->left) + 1;
}

bool CheckLeafLevel(BST* bst, int level, int* leaflevel) {
	if (bst->root == NULL) {
		return true;
	}
	if (bst->root->left == NULL && bst->root->right == NULL) {
		if (*leaflevel == 0) {
			*leaflevel = level;
			return true;
		}
		return (level == *leaflevel);
	}
	return CheckLeafLevel(&bst->root->left, level + 1, leaflevel) && CheckLeafLevel(&bst->root->right, level + 1, leaflevel);
	}
