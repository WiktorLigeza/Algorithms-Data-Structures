#include "H.h"


int main()
{
	//quantity - ilosc liczb , size - rozmiar kube³ków     np: s.start(quantity, size);

	SS s;

	cout << "zestawienie 1: rozmiar: 1000, kubelkow: 10 " << endl;
	s.start(1000,10);
	cout << endl;
	cout << endl;

	cout << "zestawienie 2: rozmiar: 10000, kubelkow: 10 " << endl;
	s.start(10000, 10);
	cout << endl;
	cout << endl;

	cout << "zestawienie 3: rozmiar: 50000, kubelkow: 10 " << endl;
	s.start(50000,10);
	cout << endl;
	cout << endl;

	cout << "zestawienie 4: rozmiar: 1000, kubelkow: 50 " << endl;
	s.start(1000,50);
	cout << endl;
	cout << endl;

	cout << "zestawienie 5: rozmiar: 10000, kubelkow: 50 " << endl;
	s.start(10000, 50);
	cout << endl;
	cout << endl;

	cout << "zestawienie 6: rozmiar: 50000, kubelkow: 50 " << endl;
	s.start(50000, 50);
	cout << endl;
	cout << endl;

	cout << "zestawienie 7: rozmiar: 1000, kubelkow: 100 " << endl;
	s.start(1000, 100);
	cout << endl;
	cout << endl;

	cout << "zestawienie 8: rozmiar: 10000, kubelkow: 100 " << endl;
	s.start(10000, 100);
	cout << endl;
	cout << endl;

	cout << "zestawienie 9: rozmiar: 50000, kubelkow: 100 " << endl;
	s.start(50000, 100);
	cout << endl;
	cout << endl;



	system("PAUSE");
	return 0;
}