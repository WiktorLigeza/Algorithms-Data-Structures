

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "BST.h"

using namespace std;

/*
void rand(int x)
{
for (int i = 0; i < x; i++)
{
a->insert(rand() % 120);
}
}
*/

int main()
{
	///def
	BST* a = new BST;

	///gen
	//srand(time(NULL));
	//rand(10);

	a->insert( 7);
	a->insert( 5);
	a->insert( 11);
	a->insert( 8);
	a->insert(15);
	a->insert(6);
	a->insert(2);
	a->insert(1);
	a->insert( 3);
	a->Print2D();

	///wyw
	cout << "pierwotny inorder:" << endl;
	//a->inorder();
	cout << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << endl;

	///---------min max
	//a->max();

	//a->min();


	///---------serch
	//a->search(8);


	///---------nast pop
	/*a->nastepnik(11);

	a->poprzednik(5);
	cout << endl;*/

	///---------rotacja L R 
	/*cout << "rotacja w lewo" << endl;
	a->rotacjaLewa();
	a->LeftSubTree();
	a->RightSubTree();
	cout << endl;*/

	cout << "----------------------------------------------------------------------" << endl;
	
	/*cout << "rotacja w prawo" << endl;
	a->rotacjaPrawa();
	a->LeftSubTree();
	a->RightSubTree();
	cout << endl;*/

	///---------del
	a->del( 5);
	a->Print2D();

	//a->delLeaves();


	//a->inorder();








	///---------end

	cout << endl;
	cout << endl;
	system("PAUSE");
	return 0;
}


