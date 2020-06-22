#include <algorithm>
#include "RBTclass.h"
#include <iostream>


using namespace std;

int main() 
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	

	RBT test;

	test.insertValue(5);
	test.insertValue(7);
	test.insertValue(12);
	test.insertValue(1);
	test.insertValue(3);
	test.insertValue(2);
	test.insertValue(15);
	test.insertValue(17);
	test.insertValue(4);
	test.insertValue(8);
	test.insertValue(0);
	test.insertValue(20);
	test.insertValue(21);
	test.insertValue(22);
	test.insertValue(6);
	test.insertValue(45);
	test.insertValue(50);
	test.insertValue(19);
	test.insertValue(23);
	test.Print2D();

	SetConsoleTextAttribute(h, 3);  cout << "------------DELETION---------" << endl;
	test.deleteValue(3);
	test.Print2D();

	
	system("PAUSE");
	return 0;
}

















//---------------------------------------------------------------------------------------------------------------------------


//test.Print2D();
//SetConsoleTextAttribute(h, 3);
//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//test.insertValue(5);
//test.insertValue(7);
//test.insertValue(12);
//test.insertValue(1);
//test.insertValue(3);
//test.insertValue(2);
//test.insertValue(15);
//test.insertValue(17);
//test.insertValue(4);
//test.insertValue(8);
//test.insertValue(0);
//test.insertValue(20);

//œledzenie 
/*SetConsoleTextAttribute(h, 3);  cout << "------------CHECKPOINT---------" << endl; test.insertValue(5); test.Print2D();
SetConsoleTextAttribute(h, 3); cout << "------------CHECKPOINT---------" << endl; test.insertValue(7); test.Print2D();
SetConsoleTextAttribute(h, 3); cout << "------------CHECKPOINT---------" << endl; test.insertValue(12); test.Print2D();
SetConsoleTextAttribute(h, 3); cout << "------------CHECKPOINT---------" << endl; test.insertValue(1); test.Print2D();
SetConsoleTextAttribute(h, 3); cout << "------------CHECKPOINT---------" << endl; test.insertValue(3); test.Print2D();
SetConsoleTextAttribute(h, 3); cout << "------------CHECKPOINT---------" << endl;  test.insertValue(2); test.Print2D();
SetConsoleTextAttribute(h, 3); cout << "------------CHECKPOINT---------" << endl;	test.insertValue(15); test.Print2D();
SetConsoleTextAttribute(h, 3); 	cout << "------------CHECKPOINT---------" << endl;	test.insertValue(17); test.Print2D();
SetConsoleTextAttribute(h, 3); 	cout << "------------CHECKPOINT---------" << endl;	test.insertValue(4); test.Print2D();
SetConsoleTextAttribute(h, 3); 	cout << "------------CHECKPOINT---------" << endl;	test.insertValue(8); test.Print2D();
SetConsoleTextAttribute(h, 3); 	cout << "------------CHECKPOINT---------" << endl;	test.insertValue(0); test.Print2D();
SetConsoleTextAttribute(h, 3); 	cout << "------------CHECKPOINT---------" << endl;	test.insertValue(20); test.Print2D();
*/