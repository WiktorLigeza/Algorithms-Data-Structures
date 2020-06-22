#pragma once

#include <iostream>
#define COUNT 10

using namespace std;

class BST
{
	struct node
	{
		int val;
		node* l;
		node* r;
		node* p;
		friend class BST;
	};

	node *root;
	node *pop;
	node *nast;


	//methods 
	void insert(node*& a, int x, node* parent = NULL);
	void inorder(node*root);
	node* max(node* root);
	node* min(node* root);
	node* search(node* root, int x);
	node* nastepnik(node* root, node*& nast, int x);
	node* poprzednik(node* root, node*& pop, int x);
	void rotacjaPrawa(node*&root);
	void rotacjaLewa(node*&root);
	node* delLeaves(node*&root);
	node* del(node*&root, int x);
	void Print2D(node* root);
	void Print2DUtil(node* root, int space);


	//public methods 
public:


	void insert(int x)
	{
		insert(root, x);
	}

	void inorder()
	{
		inorder(root);
	}

	node* max()
	{
	    max(root);
		return 0;
	}

	node* min()
	{
		node* min(root);
		return 0;
	}

	node* search(int x)
	{
		search(root, x);
		return 0;
	}

	node* nastepnik(int x)
	{
	    nastepnik(root, nast, x);
		cout << "nastepnikiem liczby "<< x <<" jest: "<< nast->val << endl;
		return 0;
	}

	node* poprzednik(int x)
	{
	    poprzednik(root, pop, x);
		cout << "poprzednikiem liczby " << x << " jest: " << pop->val << endl;
		return 0;
	}

	void rotacjaPrawa()
	{
		rotacjaPrawa(root);
	}

	void rotacjaLewa()
	{
		rotacjaLewa(root);
	}

	node* del(int x)
	{
	    del(root, x);
		return 0;
	}

	node* delLeaves()
	{
		delLeaves(root);
		return 0;
	}

	void LeftSubTree()
	{
		cout << "lewe podrzewo" << endl;
		inorder(root->l);
	}

	void RightSubTree()
	{
		cout << "prawe podrzewo" << endl;
		inorder(root->r);
	}

	void Print2D()
	{
		Print2D(root);
	}

		//constructor && destructor
		BST()
		{
			root = NULL;
			pop = NULL;
			nast = NULL;
		};

		~BST()
		{
		};
};


