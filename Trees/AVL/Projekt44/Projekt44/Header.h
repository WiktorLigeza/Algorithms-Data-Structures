
#pragma once
#include<iostream>

using namespace std;

class AVL
{
	struct node
	{
		node *l;
		node *r;
		int h;  //wysokosc
		int val;
		friend class AVL;
	};
	node *root;
	node *pop;


	//methods 
	node* insert(node*& a, int x);
	int wysokosc(node *a);
	node* RightRotate(node* &a);
	node* LeftRotate(node* &a);
	node* DoubleLeftRotate(node* &a);
	node* DoubleRightRotate(node* &a);
	void Inorder(node* a);
	void Print2DUtil(node *a, int space);
	void Print2D(node *a);
	node* Remove(int x, node* a);
	node* Min(node* a);
	node* Max(node* a);

	void rotacjaLewa(node*&a);
	void rotacjaPrawa(node*&a);



	//node* del(node*&a, int x);
	//node* poprzednik(node* root, node*& pop, int x);
	//node* maximum(node* root);

	//methods 
public:
	void insert(int x)
	{
		insert(root, x);
	}
	void Show()
	{
		Inorder(root);
		cout << endl;
	}
	void Print2D()
	{
		Print2D(root);
	}
	void Remove(int x)
	{
		Remove(x, root);
	}


	/*node* del(int x)
	{
		del(root, x);
		return 0;
	}*/



	//Cons && Des
	AVL()
	{
		root = NULL;
		pop = NULL;
	}
	~AVL()
	{
	}

};