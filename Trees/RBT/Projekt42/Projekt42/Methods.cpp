#include <algorithm>
#include <iostream>
#include "RBTclass.h"
#define COUNT 10

using namespace std;


//konstruktory
node::node(int data)
{
	this->data = data;
	color = RED;
	left = right = parent = NULL;
}

RBT::RBT()
{
	root = NULL;
}

//insert 
void RBT::insertValue(int n)
{
	node* NODE = new node(n);
	root = insertBST(root, NODE);
	fixInsertRBT(NODE);
}

node* RBT::insertBST(node*& root, node*& ptr)
{
	if (root == NULL) //*
	{
		return ptr;
	}

	if (ptr->data < root->data)
	{
		root->left = insertBST(root->left, ptr);
		root->left->parent = root;
	}
	if (ptr->data > root->data)
	{
		root->right = insertBST(root->right, ptr);
		root->right->parent = root;
	}

	return root;
}

void RBT::fixInsertRBT(node*& ptr)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	node *parent = NULL;
	node *grandpa = NULL;

	while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) //pogwa³cone zasady RBT (dwa czerwone pod rz¹d)
	{
		parent = ptr->parent;
		grandpa = parent->parent;


		if (parent == grandpa->left) // je¿eli rodzic jest lewym dizeckiem
		{
			node* uncle = grandpa->right; //to wujo jest prawym dzieckiem 
			if (getColor(uncle) == RED) //jeœli wujo jest czerwony (komuch)
			{
				//colorswap 
				//SetConsoleTextAttribute(h, 11); cout << "COLOR SWAP" << endl;
				setColor(uncle, BLACK);
				setColor(parent, BLACK);
				setColor(grandpa, RED);
				ptr = grandpa; //przechodzimy do dziadka
			}
			else
			{
				if (ptr == parent->right) //triangle case - ptr jest prwaym dzieckiem parenta ktr jest lewym dzieckiem grandpa
				{
					//SetConsoleTextAttribute(h, 11); cout << "TRIANGLE CASE" << endl;
					rotateLeft(parent);
					ptr = parent; //przechodzimy na rodzica 
					parent = ptr->parent; //ustawiamy nowego parent 
				}
				//SetConsoleTextAttribute(h, 11); cout << "LINE CASE" << endl;
				rotateRight(grandpa); // line case - pogwa³cone zasady RBT (dwa czerwone pod rz¹d)
				swap(parent->color, grandpa->color); // nastêpnie zmiana kolorów 
				ptr = parent; //przechodzimy na rodzica 
			}
		}
		else //rodzic jest prawym dzieckiem 
		{
			node* uncle = grandpa->left;
			if (getColor(uncle) == RED)
			{
				//SetConsoleTextAttribute(h, 11); cout << "COLOR SWAP" << endl;
				setColor(uncle, BLACK);
				setColor(parent, BLACK);
				setColor(grandpa, RED);
				ptr = grandpa;
			}
			else
			{
				if (ptr == parent->left) //triangle case 
				{
				//	SetConsoleTextAttribute(h, 11); cout << "TRIANGLE CASE" << endl;
					rotateRight(parent);
					ptr = parent;
					parent = ptr->parent;
				}
				//SetConsoleTextAttribute(h, 11); cout << "LINE CASE" << endl;
				rotateLeft(grandpa); //line case
				swap(parent->color, grandpa->color);
				ptr = parent;
			}
		}
	}
	setColor(root, BLACK); //root zawsze czarny 
}

//delete
void RBT::deleteValue(int data)
{
	cout << "delete value: "<< data << endl;
	node* NODE = deleteBST(root, data);
	fixDeleteRBT(NODE);
}

node* RBT::deleteBST(node*& root, int data)
{
	cout << "delete BST" << endl;
	if (root == NULL)
	{
		return root;
	}
	if (data < root->data)
	{
		return deleteBST(root->left, data);
	}
	if (data > root->data)
	{
		return deleteBST(root->right, data);
	}
	if (root->left == NULL || root->right == NULL)
	{
		cout << "thats it " << root->data << endl;
		return root;
	}
	
	cout << "usuwamy: "<<root->data << endl;
	node* temp = minValueNode(root->right);
	root->data = temp->data;
	cout << "a na jego miejsce dajemy: " << root->data << endl;
	return deleteBST(root->right, temp->data);
}

void RBT::fixDeleteRBT(node*& NODE)
{
	cout << endl;
	cout << "FIX MIX for NODE: "<< NODE->data << endl;
	if (NODE == NULL)
	{
		return;
	}
	if (NODE ==root)
	{
		root = NULL;
		return;
	}
	if (getColor(NODE) == RED || getColor(NODE->left) == RED || getColor(NODE->right) == RED) // jeœli NODE lub jego dzieci s¹ czerowne 
	{
		cout << "1 NODE lub jego dzieci sa czerowne " << endl;
		node* child = NODE->left != NULL ? NODE->left : NODE->right;  //jeœli istnieje lewe dziecko to child to lewe a jeœli nie to prawe 
		                                                    if (child != NULL) { cout << "child: " << child->data << endl; }

		if (NODE == NODE->parent->left) //jeœli NODE to lewe dziecko 
		{
			cout << "1 NODE to lewe dziecie" << endl;
			NODE->parent->left = child; //przypinamy dziecko 
			if (child != NULL)
			{
				child->parent = NODE->parent;              cout << "rodzic dziecka wskazuje na rodzica NODE" << endl;
			}

			setColor(child, BLACK);                        cout << "dziecko ustawiamy na czarne" << endl;
			delete(NODE);
		}
		else
		{
			cout << "1 NODE to prawe dziecie" << endl;
			NODE->parent->right = child;//przepinamy na prawe
			if (child != NULL)
			{
				child->parent = NODE->parent;              cout << "rodzic dziecka wskazuje na rodzica NODE" << endl;
			}

			setColor(child, BLACK);                        cout << "dziecko ustawiamy na czarne" << endl;
			delete (NODE); 
		}

	}
	else
	{
		cout << "2 ELSE " << endl;
		cout << "" << endl;
		node* sibling = NULL;
		node* parent = NULL;
		node* ptr = NODE;

		setColor(ptr, DOUBLE_BLACK); //BIG black boi

		while (ptr != root && getColor(ptr) == DOUBLE_BLACK) { //jesli big black boi i nie jest rootem
			parent = ptr->parent;
			if (ptr == parent->left)
			{
				sibling = parent->right; //rodzenstwo to po prostu drugie dziecko xd
				if (getColor(sibling) == RED)  //jesli czerwone robimy na czarne a rodzica na czerwony, rotujemy rodzica w lewo
				{
					setColor(sibling, BLACK);
					setColor(parent, RED);
					rotateLeft(parent);
				}
				else 
				{
					if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)  //jesli lewe i prawe dziecko rodzenstwa jest czzarne
					{
						setColor(sibling, RED); //zmikeniamy kolor rodzenstwa na czerwony
						if (getColor(parent) == RED) //jesli rodzic czerwony zmieniamy na czarny
						{
							setColor(parent, BLACK);
						}
						else
						{
							setColor(parent, DOUBLE_BLACK); //jesli nie to robimy big blac boi znow
						}
						ptr = parent; //wskaznik na rodzica
					}
					else
					{
						if (getColor(sibling->right) == BLACK) //jesli prawe dziecko rodzenstwa czarne lewe tez robimy czarne a rodzenstwo czerwone
						{ 
							setColor(sibling->left, BLACK);
							setColor(sibling, RED);
							rotateRight(sibling); //rotujemy rodzenstwo w prawoo
							sibling = parent->right; //rodzestwem staje sie prawe dziecko rodzica
						}
						setColor(sibling, parent->color); //ustawiamy kolor rodzenstwa na kolor rodzica
						setColor(parent, BLACK); //a rodzica na czarny
						setColor(sibling->right, BLACK); //a prawego dziecka rodzenstwa na czarny tez xd
						rotateLeft(parent); //rotujemy w lewo rodzica
						break;
					}
				}
			}
			else {
				sibling = parent->left; //jesli rodzenstwo jest lewym dzieckiem a my prawym
				if (getColor(sibling) == RED) //jego kolor jest czerwony
				{ 
					setColor(sibling, BLACK); //zmieniamy na czarny a rodzica na czerwony i rotujemy rodzica w prawo
					setColor(parent, RED);
					rotateRight(parent);
				}
				else
				{
					if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) //jesli dzieci rodzenstwa sa czarne zmieniamy kolor rodzenstwa na czerwony
					{ 
						setColor(sibling, RED);

						if (getColor(parent) == RED) //jesli rodzic jest czerwony zmieniamy na czarny
						{
							setColor(parent, BLACK);
						}
						else
						{
							setColor(parent, DOUBLE_BLACK); //jesli nie to zmieniamy na big black bull kozak podwojny cxarny
						}
						ptr = parent; //wskaznik n rodzica
					}
					else 
					{
						if (getColor(sibling->left) == BLACK)//jesli lewe dziecko rodzenstwa is black to prawe tez robimy czarne a rodzenstwo czerwone
						{ 
							setColor(sibling->right, BLACK);
							setColor(sibling, RED);
							rotateLeft(sibling); //rotujemy w lewo rodzestwo i ustawiamy na nie lewe dziecko rodzica tzn no wiadomo
							sibling = parent->left;
						}
						setColor(sibling, parent->color); //ustawiamy kolor rodzenstwa na kolor rodzica kolor rodzica na czarny a lewego dziecka rodzenstwa na czarny tez i rotujemy w prawo rodzica
						setColor(parent, BLACK);
						setColor(sibling->left, BLACK);
						rotateRight(parent);
						break;
					}
				}
			}
		}
		if (NODE == NODE->parent->left) //jesli jest lewym dzieckiem to usuwamy po prostu a jesli prawym to tak samo i nullujemy wskazniki na bachory
			NODE->parent->left = NULL;
		else
			NODE->parent->right = NULL;
		delete(NODE);
		setColor(root, BLACK); //kolor roota ma byc cxarny wiec no
	}
}
	


//segregacja rasowa
int RBT::getColor(node*& ptr)
{  
	if (ptr == NULL)
	{
		return BLACK; //liœæ s¹ czarne 
	}
	return ptr->color;
}

void RBT::setColor(node*& ptr, int colour)
{
	if (ptr == NULL)
		return;

	ptr->color = colour;
}


//min max 
node* RBT::minValueNode(node*& x )
{
	node* ptr = x;

	while (ptr->left != NULL)
	{
		ptr = ptr->left;
	}

	return ptr;
}

node* RBT::maxValueNode(node*& x)
{
	node* ptr = x;

	while (ptr->right != NULL)
	{
		ptr = ptr->right;
	}

	return ptr;
}


//rotacje 
void RBT::rotateLeft(node*& ptr)
{
	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, 10); cout << "LEFT ROTATION" << endl;
	node* rc = ptr->right; //*rc - right child
	ptr->right = rc->left;

	if (ptr->right != NULL) 
	{
		ptr->right->parent = ptr; //adopcja
	}
	rc->parent = ptr->parent;

	if (ptr->parent == NULL) //jeœli wskaŸnik na roota to ustawiamy nowego 
	{
		root = rc;
	}
	else if (ptr == ptr->parent->left) 
	{
		ptr->parent->left = rc;
	}
	else
	{
		ptr->parent->right = rc;
	}

	rc->left = ptr;
	ptr->parent = rc;
}

void RBT::rotateRight(node*& ptr)
{
	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, 10); cout << "RIGHT ROTATION" << endl;
	node* lc = ptr->left; //*lc - left child
	ptr->left = lc->right;

	if (ptr->left != NULL)
	{
		ptr->left->parent = ptr;
	}
	lc->parent = ptr->parent;

	if (ptr->parent == NULL)
	{
		root = lc;
	}
	else if (ptr == ptr->parent->left)
	{
		ptr->parent->left = lc;
	}
	else
	{
		ptr->parent->right = lc;
	}
	lc->right = ptr;
	ptr->parent = lc;
}


//print
void RBT::Print2D(node* a)
{
	Print2DUtil(root, 0);
}

void RBT::Print2DUtil(node* a, int space)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (a == NULL)
		return;
	space += COUNT;
	Print2DUtil(a->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	if (a->color == RED)
	{
		SetConsoleTextAttribute(h, 12);
		cout << a->data << "\n";
	}
	else if (a->color == BLACK)
	{
		SetConsoleTextAttribute(h, 8);
		 cout << a->data << "\n";
	}
	Print2DUtil(a->left, space);
}
