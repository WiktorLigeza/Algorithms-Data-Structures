#include "BST.h"
#include <iostream>

void BST::insert(node*& root, int x, node* parent)
{
	if (root == NULL)
	{
		root = new node;
		root->val = x;
		root->l = root->r = NULL;
		root->p = parent;
	}
	else if (root->val > x)
	{
		insert(root->l, x, root);
	}
	else
	{
		insert(root->r, x, root);
	}
}


//min max search
BST::node* BST::max(node* root)
{
	if (root)
	{
		while (root->r)
		{
			root = root->r;
		}
		//cout << "max:"<< root->val << endl;
	}
	return root;
}

BST::node* BST::min(node* root)
{
	if (root)
	{
		while (root->l)
		{
			root = root->l;
		}
		//cout << "min:" << root->val << endl;
	}
	return root;
}

BST::node* BST::search(node* root, int x)
{
	if (root)
	{
		if (root->val == x)
		{
			cout << "znaleziono wartosc: " << root->val << endl;
			return root;
		}
		else if (root->val > x)
		{
			search(root->l, x);
		}
		else
		{
			search(root->r, x);
		}
	}
	return root;
}


//nast pop
BST::node* BST::nastepnik(node* root, node*& nast, int x)
{

	if (root == NULL)
	{
		nast = NULL;
		return NULL;
	}
	if (x == root->val)
	{
		if (root->r)
		{
			nast = min(root->r);
		}
	}
	else if (x > root->val)
	{

		nastepnik(root->r, nast, x);
	}
	else
	{
		nast = root;
		nastepnik(root->l, nast, x);
	}

	return nast;
}

BST::node* BST::poprzednik(node* root, node*& pop, int x)
{
	if (root == NULL)
	{
		pop = NULL;
		return NULL;
	}
	if (x == root->val)
	{
		if (root->l)
		{
			pop = max(root->l);
		}
	}
	else if (x < root->val)
	{
		poprzednik(root->l, pop, x);
	}

	else
	{
		pop = root;
		poprzednik(root->r, pop, x);
	}
	return pop;

}


//rotacje
void BST::rotacjaPrawa(node*&root)
{
	if (root)
	{
		node* parent = root;
		root = root->l;
		node* temp = root->r;
		root->r = parent;
		parent->l = temp;
	}
}

void BST::rotacjaLewa(node*&root)
{
	if (root)
	{
		node* parent = root;
		root = root->r;
		node* temp = root->l;
		root->l = parent;
		parent->r = temp;
	}
}


//del
BST::node* BST::delLeaves(node*&root)
{
	if (root)
	{
		if (root->l == NULL && root->r == NULL)
		{
			delete root;
			return NULL;
		}

		else
		{
			root->l = delLeaves(root->l);
			root->r = delLeaves(root->r);
		}
	}
	return root;
}

BST::node* BST::del(node*&root, int x)
{
	if (root == NULL)
	{
		return root;
	}
	else if (root->val > x)
	{
		root->l = del(root->l, x);
	}
	else if (root->val < x)
	{
		root->r = del(root->r, x);
	}
	else
	{
		if (root->l == NULL && root->r == NULL)
		{
			delete root;
			return NULL;
		}

		else if (root->r == NULL)
		{
			node* temp = root;
			root = root->l;
			delete temp;
		}
		else if (root->l == NULL)
		{
			node* temp = root;
			root = root->r;
			delete temp;
		}
		else
		{
			node* pop;
			node* pom = poprzednik(root, pop, x);
			root->val = pom->val;
			root->l = del(root->l, pom->val);
		}
	}
	return root;
}



//printf
void BST::Print2D(node* root)
{
	Print2DUtil(root, 0);
}

void BST::Print2DUtil(node* root, int space)
{
	if (root == NULL)
		return;
	space += COUNT;
	Print2DUtil(root->r, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
		cout << root->val << "\n";
	Print2DUtil(root->l, space);
}

void BST::inorder(node*root)
{
	if (root)
	{
		inorder(root->l);
		cout << root->val << endl;
		inorder(root->r);
	}
}