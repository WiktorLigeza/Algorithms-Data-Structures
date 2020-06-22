#include <iostream>
#include <fstream>
#include "H.h"

using namespace std;

int main()
{
	Graf nowy;

	cout << endl; cout << endl; cout << endl; cout << "--------------------------------------------------KRUSKAL--------------------------------------------------" << endl;
	nowy.AddToLE(); //uruchamia odrazu kruskala
	
	cout << endl; cout << endl; cout << endl; cout << "--------------------------------------------------DIJKSTRA--------------------------------------------------" << endl;
	nowy.AddDijkstraToLs(); nowy.Dijkstra();

	cout << endl; cout << endl; cout << endl; cout << "--------------------------------------------------WSZERZ--------------------------------------------------" << endl;
	nowy.AddWszerzToLs(); nowy.Wszerz();

	

	system("PAUSE");
}
