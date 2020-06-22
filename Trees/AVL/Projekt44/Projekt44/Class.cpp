#include "Header.h"
#include<algorithm>
#include<iostream>
#define COUNT 10

using namespace std;

AVL::node* AVL::insert(node *&a, int x)
{
	if (a == NULL)
	{
		a = new node;
		a->val = x;
		a->h = 0;
		a->l = a->r = NULL;
	}
	else if (x < a->val)
	{
		a->l = insert(a->l, x);
		if (wysokosc(a->l) - wysokosc(a->r) == 2)
		{
			if (x < a->l->val)
			{
				a = RightRotate(a);
				//cout << " RightRotate" << endl;
			}
			else
			{
				a = DoubleRightRotate(a);
				//cout << " DoubleRightRotate" << endl;
			}
		}
	}
	else if (x > a->val)
	{
		a->r = insert(a->r, x);
		if (wysokosc(a->r) - wysokosc(a->l) == 2)
		{
			if (x > a->r->val)
			{
				a = LeftRotate(a);
				//cout << " LeftRotate" << endl;
			}
			else
			{
				a = DoubleLeftRotate(a);
				//cout << " DoubleLeftRotate" << endl;
			}
		}
	}


	//update wysokoœci 
	a->h = max(wysokosc(a->l), wysokosc(a->r)) + 1; 
	return a;
}

int AVL::wysokosc(node *a)
{
	return (a == NULL ? -1 : a->h);
}

AVL::node* AVL::RightRotate(node* &a)
{
	node* b = a->l;
	a->l = b->r;
	b->r = a;
	a->h = max(wysokosc(a->l), wysokosc(a->r)) + 1;
	b->h = max(wysokosc(b->l), a->h) + 1;
	return b;
}

AVL::node * AVL::LeftRotate(node* &a) //rozpatruj globalnie, pamiêtaj ¿e zwracasz wêze³ b.          np: a = LeftRotate(a); ==> a = b; 
{
	node* b = a->r;
	a->r = b->l;
	b->l = a;
	a->h = max(wysokosc(a->l), wysokosc(a->r)) + 1;
	b->h = max(wysokosc(b->r), a->h) + 1;
	return b;
}

AVL::node * AVL::DoubleLeftRotate(node* &a)
{
	a->r = RightRotate(a->r);
	return LeftRotate(a);
}

AVL::node * AVL::DoubleRightRotate(node* &a)
{
	a->l = LeftRotate(a->l);
	return RightRotate(a);
}

void AVL::Inorder(node* a)
{
	if (a == NULL)
		return;
	Inorder(a->l);
	cout << a->val << " ";
	Inorder(a->r);
}

void AVL::Print2DUtil(node* a, int space)
{
	if (a == NULL)
		return;
	space += COUNT;
	Print2DUtil(a->r, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << a->val << "\n";
	Print2DUtil(a->l, space);
}

void AVL::Print2D(node* a)
{
	Print2DUtil(root, 0);
}

void AVL::rotacjaLewa(node*&a)
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

void AVL::rotacjaPrawa(node*&a)
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

AVL::node* AVL::Remove(int x, node* a)
{
	node* temp;
	if (a == NULL)  
	{
		return NULL;
	}

	//jesli szukany element jest rootem
	else if (x == a->val && a == root) 
	{
		cout << "usuwanie roota" << endl;
		int pom = root->val;
		root->val = Min(root->r)->val;  
		Min(root->r)->val = pom;
		a->r = Remove(x, a->r);

		//ogólnie to szukamy nastêpnika, zmieniamy wartoœci roota 
		//na wartoœci nastêpnika, nastêpnie wywo³ujemy funkcjê usuniêcia 
	}

	//wyszukiwanie elementu
	else if (x < a->val)
	{
		a->l = Remove(x, a->l);
	}
	else if (x > a->val)
	{
		a->r = Remove(x, a->r);
	}

	
	//jesli element ma dwojke dzieci
	else if (a->l && a->r) 
	{
		temp = Min(a->r); 
		a->val = temp->val;
		a->r = Remove(a->val, a->r); 
	}

	//jesli ma jedno lub wcale dzieci
	else 
	{
		temp = a;
		if (a->l == NULL)
		{
			a = a->r;
		}
		else if (a->r == NULL)
		{
			a = a->l;
		}
		delete temp;
	}


	if (a == NULL)
	{
		return a;
	}

	a->h = max(wysokosc(a->l), wysokosc(a->r)) + 1;//update wysokosci


	//balans------------------------------


	//Right case
	if (wysokosc(a->l) - wysokosc(a->r) == 2) 
	{
		
		if (wysokosc(a->l->l) - wysokosc(a->l->r) == 1)
		{
			//rotacjaPrawa(a);
			cout << "RightRotate" << endl;
			return RightRotate(a);
		}

		else //right left case
		{
			cout << "DoubleRightRotate" << endl;
			return DoubleRightRotate(a);
		}
	}

	//Left case
	else if (wysokosc(a->r) - wysokosc(a->l) == 2)
	{

		 if (wysokosc(a->r->r) - wysokosc(a->r->l) == 1)
		{
		    //rotacjaLewa(a);
			cout << "LeftRotate" <<a->val << endl; 
		    return LeftRotate(a);

		}
		else //left right case
		{
			cout << "DoubleLeftRotate" << endl;
			return DoubleLeftRotate(a);
		}
	}
	return a;
}

AVL::node * AVL::Min(node* a)
{
	if (a == NULL)
		return NULL;
	else if (a->l == NULL)
		return a;
	else
		return Min(a->l);
}

AVL::node * AVL::Max(node* a)
{
	if (a == NULL)
		return NULL;
	else if (a->r == NULL)
		return a;
	else
		return Max(a->r);
}


//AVL::node* AVL::del(node*&a, int x)
//{
//		if (a == NULL)
//		{
//			return a;
//		}
//		else if (a->val > x)
//		{
//			a->l = del(a->l, x);
//		}
//		else if (a->val < x)
//		{
//			a->r = del(a->r, x);
//		}
//		else //jesli juz znaleziona 
//		{
//			if (a->l == NULL && a->r == NULL)
//			{
//				delete a;
//				return NULL;
//			}
//
//			else if (a->r == NULL)
//			{
//				node* temp = a;
//				a = a->l;
//				delete temp;
//			}
//			else if (a->l == NULL)
//			{
//				node* temp = a;
//				a = a->r;
//				delete temp;
//			}
//			else
//			{
//				node* pom = poprzednik(a, pop, x);
//				a = pom;
//				a->l = del(a->l, pom->val);
//			}
//		}
//		return a;
//}
//
//AVL::node* AVL::poprzednik(node* a, node*& pop, int x)
//{
//	if (a == NULL)
//	{
//		pop = NULL;
//		return NULL;
//	}
//	if (x == a->val)
//	{
//		if (a->l)
//		{
//			pop = maximum(a->l);
//		}
//	}
//	else if (x < a->val)
//	{
//		poprzednik(a->l, pop, x);
//	}
//
//	else
//	{
//		pop = a;
//		poprzednik(a->r, pop, x);
//	}
//	return pop;
//
//}
//
//AVL::node* AVL::maximum(node* a)
//{
//	if (a)
//	{
//		while (a->r)
//		{
//			a = a->r;
//		}
//		//cout << "max:"<< root->val << endl;
//	}
//	return a;
//}