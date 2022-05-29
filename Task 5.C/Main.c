#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TreePrintLibrary.h"
//#include "BST.c"

void main() {
	BST bst;
	initBST(&bst);
	insertBST(&bst, 3);
	insertBST(&bst, 1);
	insertBST(&bst, 5);
	insertBST(&bst, 4);
	insertBST(&bst, 8);
	print_ascii_tree(bst.root);
	printTreeInorder(&bst);
	//destroyBST(&bst);
	printf("\n");
	printf("The number is %d" , findIndexNFromLast(&bst, 5));
}