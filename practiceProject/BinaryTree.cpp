// projectHash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BinaryTree.h"

using namespace std;

//template<typename T> bTree<T>* bTree<T>::head = NULL;

template <typename T> void bTree<T>::insertNR(T element)
{
	struct node* temp = new (struct node);
	temp->data = element;
	temp->left = NULL;
	temp->right = NULL;

	queue <struct node*> tempq;
	
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		struct node* ptr = head;
		tempq.push(ptr);
		while (tempq.size())
		{
			ptr = tempq.front();
			if (ptr->left == NULL)
			{
				ptr->left = temp;
				break;
			}
			else if (ptr->right == NULL)
			{
				ptr->right = temp;
				break;
			}
			else
			{
				tempq.pop();
				tempq.push(ptr->left);
				tempq.push(ptr->right);
			}
		}
	}
}
template <typename T> void bTree<T>::inorderNR(struct node* n)
{
	if (n == NULL)
		return;

	myStack<struct node*> stk;
	struct node* p;
	do
	{
		while (n != NULL)
		{
			stk.push(n);
			n = n->left;
		}
		n = stk.stackTop();
		cout << n->data << ",";
		stk.pop();

		p = stk.stackTop();
		cout << p->data << ",";
		stk.pop();
		
	
		if (p->right != NULL)
		{
			stk.push(p->right);
			n = p->right->left;
		}
		
		
	} while (stk.size());
}

template <typename T> int bTree<T>::countLeafNodesNR(struct node* n)
{
	queue <struct node*> tmpq;
	tmpq.push(n);
	int count = 0;

	while (tmpq.size())
	{
		n = tmpq.front();
		if (n->left == NULL && n->right == NULL)
			count++;
		else
		{
			if (n->left != NULL)
				tmpq.push(n->left);
			if (n->right != NULL)
				tmpq.push(n->right);
		}
	}
	return count;
}	

template <typename T> int bTree<T>::treeDepthNR(struct node* n)
{
	int depth=0;
	queue<struct node*> tmpq;
	if (n != NULL)
		tmpq.push(n);

	while (tmpq.size())
	{
		int curSize = tmpq.size();
		for (int i = 0; i < curSize; i++)
		{
			n = tmpq.front();
			if (n != NULL)
				tmpq.pop();

			if (n->left != NULL)
				tmpq.push(n->left);
			if (n->right != NULL)
				tmpq.push(n->right);
			}
		depth++;
	}
	return depth;
}

/*
Recursive
*/

template <typename T> void bTree<T>::inorder(struct node* n)
{
	if(n->left != NULL)
		this->inorder(n->left);

	cout << n->data << ",";

	if(n->right != NULL)
		this->inorder(n->right);
}

template <typename T> void bTree<T>::preorder(struct node* n, int indent)
{
	if (n == NULL)
		return;

	for (int i = 0;i < indent;i++)
		cout << " ";
	cout << n->data << endl;
	for (int i = 0;i < indent-1; i++)
		cout << " ";
	cout << "/ \\" << endl;
	this->preorder(n->left, indent-(indent/2));
	this->preorder(n->right, indent+(indent/2));
}

template <typename T> void bTree<T>::printTree(struct node* n, int indent)
{
	if (n == NULL)
		return;
	queue<struct node*> levelq;
	levelq.push(n);
	struct node* ptr;
	int curSize, adj;

	while (levelq.size())
	{
		curSize = levelq.size();
		cout << endl;
		for (int i = 0;i < curSize; i++)
		{
			ptr = levelq.front();
			i ? adj = 2 : adj = 1;

			for (int j = 0; j < adj*indent;j++)
				cout << " ";
			cout << ptr->data;

			if(ptr->left != NULL)
				levelq.push(ptr->left);
			if(ptr->right != NULL)
				levelq.push(ptr->right);

			levelq.pop();
		}
		cout << endl;

		for (int i = 0; i < curSize; i++)
		{
			i ? adj = 2 : adj = 1;
			for (int j = 0; j < adj*indent-1;j++)
				cout << " ";
			cout << "/ \\";
		}
		cout << endl;
		indent = indent >> 1;
	}
}

template <typename T> int bTree<T>::countLeafNodes(struct node* n)
{
	if (n == NULL)
		return 0;

	if (n->left == NULL && n->right == NULL)
		return 1;
	
	return	this->countLeafNodes(n->left) + this->countLeafNodes(n->right);
}

template <typename T> int bTree<T>::isBST(struct node* n) {
	if (n == NULL)
		return 1;

	if (isLeftSubTreeSmaller(n->left, n->data) && isRightSubTreeLarger(n->right, n->data))
		if (isBST(n->left))
			if (isBST(n->right))
				return 1;
			else
				return 0;
		else
			return 0;
	else
		return 0;
}

template <typename T> int bTree<T>::isLeftSubTreeSmaller(struct node* n, int data)
{
	if (n == NULL)
		return 1;

	if (isLeftSubTreeSmaller(n->left, data))
		if (isLeftSubTreeSmaller(n->right, data))
			if (n->data < data)
				return 1;
			else
				return 0;
		else
			return 0;
	else
		return 0;
}

template <typename T> int bTree<T>::isRightSubTreeLarger(struct node* n, int data)
{
	if (n == NULL)
		return 1;

	if (isRightSubTreeLarger(n->left, data))
		if (isRightSubTreeLarger(n->right, data))
			if (n->data > data)
				return 1;
			else
				return 0;
		else
			return 0;
	else
		return 0;
}

template <typename T> int bTree<T>::isABST(struct node* root) {
	static struct node* prev = NULL;

	if (root == NULL)
		return 1;

	if (!isBST(root->left))
		return 0;

	if (prev != NULL && root->data <= prev->data)
		return 0;

	prev = root;
	return isBST(root->right);
}

//template <class T> 
int binaryTree()
{
	/********************
	Binary Tree practice
	*********************/
	bTree<int> bt;	
	bt.initBT();

	int array[10] = {6,4,8,2,5,7,9,1,3 };
	for (int i = 0; i < 9;i++)
		bt.insertNR(array[i]);

	bt.inorder(bt.headnode());
	//cout << endl;
	//cout << "Leaf nodes count:" << bt.countLeafNodes(bt.headnode());

	//bt.preorder(bt.headnode(), *bt.countLeafNodes(bt.headnode()));
	bt.printTree(bt.headnode(), 2 * bt.countLeafNodes(bt.headnode()));

	//bt.inorderNR(bt.headnode());

	//cout << endl << "Leaf node NR:" << bt.countLeafNodesNR(bt.headnode()) << endl;

	cout << endl << "Tree depth:" << bt.treeDepthNR(bt.headnode());

	cout << endl << "Is BST:" << bt.isBST(bt.headnode()) << "ABST:" << bt.isABST(bt.headnode());

	return 0;
}

