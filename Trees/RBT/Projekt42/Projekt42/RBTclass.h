

#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H
#include <Windows.h>
#include <iostream>


enum Color { RED, BLACK, DOUBLE_BLACK };

struct node
{
	int data;
	int color;
	node *left, *right, *parent;
	explicit node(int);
};

class RBT
{
private:
	node *root;

	//print
	void Print2DUtil(node *a, int space);
	void Print2D(node *a);

protected:
	//insert
	node* insertBST(node*&, node*&);
	void fixInsertRBT(node*&);

	//delete
	node* deleteBST(node*& root, int data);
	void fixDeleteRBT(node*& node);



	//segregacja rasowa
	int getColor(node*&);
	void setColor(node*&, int);

	//min max
	node* minValueNode(node*& x);
	node* maxValueNode(node*& x);

	//rotacje
	void rotateLeft(node*&);
	void rotateRight(node*&);




public:
	void insertValue(int);
	void deleteValue(int data);
	void Print2D()
	{
		Print2D(root);
	}


	RBT();
};

#endif
#pragma once
