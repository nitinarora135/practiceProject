#pragma once
#include "stdafx.h"
#include <iostream>
#include <list>
#include <queue>
#include <map>

template <typename T> class bTree {
	struct node {
		T data;
		struct node* left;
		struct node* right;
	} *head;

	//struct node* head;
public:
	void initBT() { head = NULL; }
	struct node* headnode() { return head; }
	/**********************
	Non-recursive routines
	**********************/
	void insertNR(T data);
	void inorderNR(struct node*);
	int countLeafNodesNR(struct node*);
	int treeDepthNR(struct node*);
	/*******************
	*Recursive routines*
	*******************/
	void inorder(struct node*);
	void preorder(struct node*, int indent);
	void postorder();
	int countLeafNodes(struct node*);
	void printTree(struct node*, int indent);
	int isBST(struct node*);
	int isLeftSubTreeSmaller(struct node*, int data);
	int isRightSubTreeLarger(struct node*, int data);
	int countRangeNodes(struct node* n, int min, int max);
	int sumR2L(struct node* n, int isum);
	static int mergeTree(struct node* t1, struct node* t2);

	int isABST(struct node*);

};

extern int binaryTree();