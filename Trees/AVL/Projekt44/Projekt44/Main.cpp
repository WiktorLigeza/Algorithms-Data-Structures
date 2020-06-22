#include"Header.h"
#include<ctime>
#include<iostream>

using namespace std;


//void random(AVL* c)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		c->Insert(rand() % 50);
//	}
//}


int main() {

	srand(time(NULL));

	AVL* a = new AVL;
	//random(ana);
	a->insert(50);

	a->insert(40);
	a->insert(60);

	a->insert(70);
	a->insert(55);
	a->insert(35);
	a->insert(45);

	a->insert(85);
	a->insert(65);
	a->insert(57);
	a->insert(54);
	a->insert(47);
	a->insert(43);
	a->insert(37);
	a->insert(34);

	a->insert(87);
	a->insert(84);
	a->insert(66);
	a->insert(58);
	a->insert(48);
	a->insert(46);
	a->insert(44);
	a->insert(38);

	a->insert(88);
	a->insert(49);

	cout << endl;
	cout << endl;
	a->Show(); cout << endl;
	a->Print2D(); cout << "--------check------------" << endl;
	cout << endl;
	cout << endl;
	a->Remove(47);
	a->Show(); cout << endl;
	a->Print2D();
	cout << endl;
	cout << endl;

	

	system("PAUSE");
	return 0;

	///ctr + c 
	//	a->Print2D(); cout << "--------check------------" << endl;
	//  a->Print2D();
	//	a->Show();
}