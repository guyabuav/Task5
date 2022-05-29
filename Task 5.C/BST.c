#define CRT_SECURE_NO_WARNINGS
#include "TreePrintLibrary.h"
#include "BST.h"
#include <stdio.h>
#define AllocationCheck \
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
		AllocationCheck;
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
// return findIndexNFromLast(&bst->root->right,N-1);
//
int findIndexNFromLast(BST* bst, int N) {
	int num = 0;
	/*if (N = 0) {
		return bst->root->element;
	}*/
	//return findIndexNFromLast(&bst->root->right, N - 1);
	if (bst->root != NULL) {
		num = findIndexNFromLast(&bst->root->right,N);
		if (num != 0 && num != NULL) {
			return num;
		}
		N -= 1;
		if (N == 0) {
			return bst->root->element;
		}
		num = findIndexNFromLast(&bst->root->left,N - 1);
		if (num != 0 && num != NULL) {
			return num;
		}
		N -=1;
		if (N == 0) {
			return bst->root->element;
		}
		
	}
	return NULL;
}

int sameHeightLeaves(BST* bst) {
	if (bst->root == NULL) {
		return 1;
	}
	
}