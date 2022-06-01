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
	insertBST(&bst, 2);
	insertBST(&bst, 0);
	insertBST(&bst, 5);
	insertBST(&bst, 4);
	insertBST(&bst, 8);
	//insertBST(&bst, 9);
	print_ascii_tree(bst.root);
	printTreeInorder(&bst);
	printf("\n");
	printf("The number of roots is %d\n" , CountRoots(&bst.root));
	int temp = findIndexNFromLast(&bst, 5);
	if (temp) {
		printf("The NfromLAST number is %d\n", temp);
	}
	
	if (sameHeightLeaves(&bst.root)) {
		printf("SameLevel for every path\n");
	}
	else printf("Not the same level for every path\n");
	destroyBST(&bst);
	
}
