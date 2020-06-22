#include "H.h"
#include <iostream>
#include <fstream>
using namespace std;


///LE
void Graf::AddToLE() 
{
	fstream plik;
	plik.open("macierz.txt");

	int current_number;

	plik >> size;
	LE* list = new LE;


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i < j)
			{
				plik >> current_number;
			}
			else
			{
				plik >> current_number;
				if (current_number != 0)
				{
					list->add(i, j, current_number, list);
				}
			}
		}
	} // - end of matrix

	list->fix(list);

	cout << endl;  cout << "unsorted list:" << endl;
	list->print(list);

	list->mergesort(list);
	cout << endl;  cout << "sorted list:" << endl;
	 list->print(list); cout << endl;
	 list->K(list, size);

}
//AddtoLE rel
void Graf::LE::add(int from, int to, int weight, LE*& head) //dodaj do listy wierzchołków (typowa lista nihil novi) 
{
	LE* p = new LE;
	p->from = from;
	p->to = to;
	p->weight = weight;
	p->next = head;
	head = p;
}
void Graf::LE::fix(LE*& head) // coś dodaje ostatni element niepotrzebnie o wartości 0, trzeba go znaleźć i usunąć 
{
	LE* p = head;

	while (p->next->weight != 0)
	{
		p = p->next;
	}

	delete p->next;
	p->next = NULL;
}
void Graf::LE::print(LE* head)
{
	while (head)
	{
		cout << "from: " << head->from << ", to: "<<head->to << ", weight: " << head->weight << endl;
		head = head->next;

	}
}


//mergesort
void Graf::LE::mergesort(LE*& head)
{
	{
		LE *pom = head;
		LE *a;
		LE *b;

		if ((head == NULL) || (head->next == NULL))
		{
			return;
		}
		split(head, a, b);

		mergesort(a);
		mergesort(b);

		head = sortmerge(a, b);
	}
}
void Graf::LE::split(LE*source, LE *& front, LE*&back)
{
	LE * fast;
	LE * slow; //pomocnicze
	slow = source;
	fast = source->next;

	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	front = source;
	back = slow->next;
	slow->next = NULL;
}
Graf::LE* Graf::LE::sortmerge(LE* a, LE* b)
{
	LE * result = NULL;

	if (a == NULL)
	{
		return (b);
	}
	else if (b == NULL)
	{
		return(a);
	}

	if (a->weight <= b->weight)
	{
		result = a;
		result->next = sortmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortmerge(a, b->next);
	}
	return(result);
}


///node
void Graf::node::Add_node(node*& array, int weight, int to)
{
	node* p = new node;
	p->to = to;
	p->weight = weight;
	p->next = array;
	array = p;
}
//Add_node rel
void Graf::node::print_node1(node* NODE, int i )
{
	cout<< "ls" << "["<<i<<"]";
	while (NODE)
	{
		cout <<"->(weight:"<< NODE->weight<<", to:"<<NODE->to<<")";
		NODE = NODE->next;
	}
	cout << endl;
}
void Graf::PRINT()
{
	cout << "print ls: " << endl;
	for (int i = 0; i < size; i++)
	{
		ls[i]->print_node1(ls[i], i);
	}
}
void Graf::PRINTDIJKSTRA()
{
	cout << "print ls: " << endl;
	for (int i = 1; i <= size; i++)
	{
		ls[i]->print_node1(ls[i], i);
	}
}

///ls
void Graf::AddWszerzToLs()
{
	fstream plik;
	plik.open("macierz.txt");

	int current_number;

	plik >> size;
	ls = new node*[size];

	for (int i = 0; i < size; i++)
	{
		ls[i] = NULL;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			plik >> current_number;

			if (current_number != 0)
			{
				ls[i]->Add_node(ls[i], current_number, j);
			}
		}
	}


	PRINT();
}
void Graf::AddDijkstraToLs()
{
	fstream plik;
	plik.open("Dijkstra.txt");

	int current_number;

	plik >> size;
	ls = new node*[size];

	for (int i = 1; i <= size; i++)
	{
		ls[i] = NULL;
	}

	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			plik >> current_number;

			if (current_number != 0)
			{
				ls[i]->Add_node(ls[i], current_number, j);
			}
		}
	}


	PRINTDIJKSTRA();
}

//ls rel
void Graf::list::print_list1(list* root)
{
	while (root)
	{
		cout << root->val << "->";

		root = root->next;
	}
	cout << "NULL";
}
bool Graf::list::is_it_on_list(int val, list* root)
{
	bool output = true;

	while (root)
	{
		if (val == root->val)
		{
			output = false;
		}
		root = root->next;
	}

	return output;
}
void Graf::list::add(int value, list*& root)
{
	if (is_it_on_list(value, root)) //jeżeli jest na liście zwracamy false żeby nie doddać tego samego raz jeszcze
	{
		list* p = root;
		list* b = new list;
		b->val = value;
		if (root)
		{
			while (p->next)
			{
				p = p->next;
			}
			p->next = b;
			p->next->next = NULL;
		}
		else
		{
			root = b;
			root->next = NULL;
		}
	}
}
//Graf::list* Graf::list::find_and_return(int value, list* root)
//{
//	list* node = new list;
//
//	while (root)
//	{
//		if (value == root->val)
//		{
//			node = root;
//			return node;
//		}
//		root = root->next;
//	}
//
//	return NULL;
//}


///tab Kruskal
void print_id(int size)
{
	cout << "             ";
	for (int i = 0; i < size; i++)
	{
		cout << i << " ";
	}
	cout << "           ";
	for (int i = 0; i < size; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;
}
void print_array(int* tab1, int* tab2, int size, int id)
{
	if (id < 10)
	{
		cout << id << "  .Colour: [";
		for (int i = 0; i < size; i++)
		{
			cout << tab1[i] << " ";
		}
		cout << "]";
	}
	else
	{
		cout << id << " .Colour: [";
		for (int i = 0; i < size; i++)
		{
			cout << tab1[i] << " ";
		}
		cout << "]";
	}
		



	cout << " Forest: [";
	for (int i = 0; i < size; i++)
	{
		cout << tab2[i] << " ";
	}
	cout << "]";

	cout << endl;
}
void zero_array(int* tab1, int* tab2, int size)
{
	for (int i = 0; i < size; i++)
	{
		tab1[i] = 0;
	}



	for (int i = 0; i < size; i++)
	{
		tab2[i] = 0;
	}
}

//void print_arrayDijkstra(int* tab1, int* tab2, int* tab3, int size, int id)
//{
//	if (id < 10)
//	{
//		cout << id << "  .Colour: [";
//		for (int i = 1; i <= size; i++)
//		{
//			cout << "  "<<tab1[i];
//		}
//		cout << "]";
//	}
//	else
//	{
//		cout << id << " .Colour: [";
//		for (int i = 1; i <= size; i++)
//		{
//			cout << tab1[i] << "  ";
//		}
//		cout << "]";
//	}
//
//	
//
//	cout << " Prev: [";
//	for (int i = 1; i <= size; i++)
//	{
//		if (tab2[i] < 0 || tab2[i]>9)
//		{
//			cout << " "<< tab2[i];
//		}
//		else
//		{
//			cout << "  " << tab2[i];
//		}
//	}
//	cout << "]";
//
//
//	cout << " weight: [";
//	for (int i = 1; i <= size; i++)
//	{
//		if (tab3[i] < 0 || tab3[i]>9)
//		{
//			cout << " " << tab3[i];
//		}
//		else
//		{
//			cout << "  " << tab3[i];
//		}
//	}
//	cout << "]";
//
//	cout << endl;
//}
//void print_id_Dijkstra(int size)
//{
//	cout << endl;
//	cout << endl;
//	cout << "               ";
//	for (int i = 1; i <= size; i++)
//	{
//		cout << i << "  ";
//	}
//	cout << "         ";
//	for (int i = 1; i <= size; i++)
//	{
//		cout << i << "  ";
//	}
//	cout << "           ";
//	for (int i = 1; i <= size; i++)
//	{
//		cout << i << "  ";
//	}
//	cout << endl;
//	cout << endl;
//
//}

///tab Dijkstra
void set_array(int* tab1, int* tab2, int* tab3, int size)
{
	for (int i = 1; i <= size; i++)
	{
		tab1[i] = 0;
	}



	for (int i = 1; i <= size; i++)
	{
		tab2[i] = -1;
	}



	for (int i = 1; i <= size; i++)
	{
		tab3[i] =0;
	}

}
int findMin(int* tab, int size, int* colour)
{
	int j = 1;
	int i;
	int temp = 10000;
	for (i = 1; i<= size; i++) //znajdź najmniejszą droge 
	{
		if (temp > tab[i] && tab[i] != 0 && colour[i] != 2) // 0 oznacza jeszcze nie zmieniony && szukany node nie może być czarny
		{
			temp = tab[i];
		}
	}
	
	if (temp == 10000){ return (-1); } //zabezpieczenie 
	
	
	while (temp != tab[j] || colour[j] == 2) //znajdź dowiązanie do którego prowadzi najkrótsza droga ale jego kolor nie jest czarny 
	{
		j++;
	}
}
void finalexpo(int* tab1, int* tab2, int* tab3, int size,int id)
{
//
	cout << endl;
	cout <<id<< " .DIJKSTRA:" << endl;
	cout << "    Nodes: [";
	for (int i = 1; i <= size; i++)
	{
		cout <<"  "<< i ;
	}
	cout << "]" << endl;

//
	cout << "   Colour: [";
	for (int i = 1; i <= size; i++)
	{
		cout << "  " << tab1[i];
	}
	cout << "]" << endl;

//
	cout << "     Prev: [";
	for (int i = 1; i <= size; i++)
	{
		if (tab2[i] < 0 || tab2[i]>9)
		{
			cout << " " << tab2[i];
		}
		else
		{
			cout << "  " << tab2[i];
		}
	}
	cout << "]" << endl;

//
	cout << "   weight: [";
	for (int i = 1; i <= size; i++)
	{
		if (tab3[i] < 0 || tab3[i]>9)
		{
			cout << " " << tab3[i];
		}
		else
		{
			cout << "  " << tab3[i];
		}
	}
	cout << "]";

	cout << endl;
	cout << endl;




}
//int ktr(int* node, int pom)
//{
//	int i = 1;
//	while (pom != node[i] )
//	{
//		i++;
//	}
//	return i;
//}
bool isAllBlack( int size, int* colours, int j)
{
	for (int i = 1; i <= size; i++)
	{
		if (colours[i] == 2)
		{
			j++;
		}
	}
	if (j == size) { return true;}
	else { return false;}
}
//int findMax(int* tab, int size)
//{
//	int temp;
//	for (int i = 1; i <= size; i++)
//	{
//		if (temp < tab[i])
//		{
//			temp = tab[i];
//		}
//	}
//	return temp;
//}


///graph sys
Graf::list* Graf::Wszerz()
{
	list* Root_Q = NULL;
	Root_Q->add(0, Root_Q);
	list* been = NULL;
	been->add(0, been);
	node* p = new node;

	while (Root_Q)
	{
		p = ls[Root_Q->val];
		while (p)
		{
			if (been->is_it_on_list(p->to, been))  //czy jest już na liście been? jeśli jest pomijamy 
			{
				
				been->add(p->to, been); //dodajemy na listę odwiedzoncyh
				Root_Q->add(p->to, Root_Q); //dodajemy na listę do odwiedzenia
			}

			p = p->next;
		}
	//	cout << endl;  cout << "Root_Q: "; Root_Q->print_list1(Root_Q);
		Root_Q = Root_Q->next; 
	}
	cout << endl; cout << endl; cout << "WSZERZ: ";been->print_list1(been); cout << endl;

	return Root_Q;
}
void Graf::LE::K(LE*& head, int size)
{
	int* colours = new int[size];
	int* forest = new int[size];
	int inc = 1;
	int p;
	LE* LER = new LE;
	int id = -1;


	zero_array(colours, forest, size);
	cout << endl; cout << "KRUSKAL ARRAYS SYSTEM:" << endl;	cout << endl;
	print_id(size);

	while (head)
	{
		if (colours[head->from] == 0 && colours[head->to] == 0)
		{
			//zmiana koloru
			colours[head->to] = 1;
			colours[head->from] = 1;

			//przypisanie do lasu 
			forest[head->to] = inc;
			forest[head->from] = inc;
			inc++;

			//wpisanie do listy 
			LER->add(head->from, head->to, head->weight, LER);
		}
		else if (colours[head->from] == 0 && colours[head->to] == 1)
		{
			colours[head->to] = 1;
			colours[head->from] = 1;

			//podpięcie do tego samego lasu 
			forest[head->from] = forest[head->to]; 

			LER->add(head->from, head->to, head->weight, LER);
		}
		else if (colours[head->from] == 1 && colours[head->to] == 0)
		{
			colours[head->to] = 1;
			colours[head->from] = 1;

			forest[head->to] = forest[head->from]; 

			LER->add(head->from, head->to, head->weight, LER);
		}
		else if (colours[head->from] == 1 && colours[head->to] == 1)
		{
			if (forest[head->from] != forest[head->to])
			{
				inc++; 

				int forest1 = forest[head->from];
				int forest2 = forest[head->to];

				for (int i = 0; i < size; i++)
				{
					if (forest[i] == forest1 || forest[i] == forest2)
					{
						forest[i] = inc;
					}
				}
				LER->add(head->from, head->to, head->weight, LER);
			}
		}
		id++;
		print_array(colours, forest, size, id);
		head = head->next;

	} //--end of while
	LER->fix(LER);
	cout << endl; cout << endl; cout << "KRUSKAL LER: " << endl; LER->print(LER);
}
void Graf::Dijkstra()
{
	//tab
	int* colours = new int[size];
	int* prev = new int[size];
	int* weight = new int[size];

	int id;
	int here;
	int j;

	//inicjalizacja
	cout << endl; cout << endl;
	set_array(colours, prev, weight, size);
	node* p = new node;
	id = 1;
	here = 1;
	j = 1;

	while (true)
	{
		cout << "jestesmy tu: "<<here;
		j = 0; //zerujemy sprawdzenie stanu
		p = ls[here]; //ładujemy nody z listy sąsiedztwa dla obecnego noda
		while (p)
		{
			//set val
			if (colours[p->to] != 2)
			{
				colours[p->to] = 1;
				if (weight[p->to] > (weight[here] + p->weight) || weight[p->to] == 0)
				{
					weight[p->to] = p->weight + weight[here];
					prev[p->to] = here;
				} 
			}
			p = p->next;
		}
		colours[here] = 2; // ustawiamy node z wyczerpaną liczbą somsiedztwa na czarno (odiwedzony) 
		here = findMin(weight, size, colours); //przechodzimy do noda do którego droga jest najkrótsza       
		finalexpo(colours, prev, weight, size, id); id++; //wypisz obecny stan
		if (isAllBlack(size,colours,j)) break; //jeżeli wszystkie nody odwiedzone kończymy zabawe
	}
	
	cout << "---------------------------------FINAL--------------------------------- " << endl;
	finalexpo(colours, prev, weight, size, id);
}


///cons
Graf::Graf()
{
	ls = NULL;
	size = NULL;
}
Graf::LE::LE()
{
	from = NULL;
	to = NULL;
	weight = NULL;
	next = nullptr;
}






///BACKUP1
//Graf::list* Graf::Dijkstra()
//{
//	//tab
//	int* colours = new int[size];
//	int* prev = new int[size];
//	int* weight = new int[size];
//	int* listonosz = new int[size];
//
//	int black = 2;
//	int grey = 1;
//	int id = 1;
//	int here;
//	int pom;
//
//
//	//print_id_Dijkstra(size);
//	set_array(colours, prev, weight, size);
//
//	//struktury
//	list* lista = NULL;
//	list* D = NULL;
//	node* p = new node;
//
//	//inicjalizacja
//	lista->add(1, lista); //zaczynamy od 1 
//	here = 1;
//
//
//
//
//	while (lista)
//	{
//
//		p = ls[lista->val]; //ładujemy nody dla danej listy
//
//		while (p)
//		{
//			//set val
//			if (colours[p->to] != 2)
//			{
//				colours[p->to] = 1;
//				if (weight[p->to] > (weight[here] + p->weight) || weight[p->to] == 0)
//				{
//					weight[p->to] = p->weight + weight[here];
//					prev[p->to] = here;
//				}
//
//				lista->add(p->to, lista); //dodajemy na listę do odwiedzenia
//			}
//			p = p->next;
//		}
//		colours[here] = 2; // ustawiamy node z wyczerpaną liczbą sąsiedztwa na czarno (odiwedzony) 
//
//		finalexpo(colours, prev, weight, size, id); id++;
//
//		pom = findMin(weight, size, colours); //przechodzimy do noda do którego droga jest najkrótsza 
//
//
//
//											  //lista = lista->find_and_return(pom,lista); //znajdujemy na liście do odwiedzenia wybrany element(najmniejszy)
//											  //lista = lista->next;
//		if (lista) //zabezpieczenie 
//		{
//			here = lista->val; //here pokazuje ktr node na liście jest bierzący 
//		}
//		else
//		{
//			cout << "---------------------------------FINAL--------------------------------- " << endl;
//			finalexpo(colours, prev, weight, size, id);
//			return lista;
//		}
//	}
//	cout << "---------------------------------FINAL--------------------------------- " << endl;
//	finalexpo(colours, prev, weight, size, id);
//	return lista;
//}


///BACKUP2
//Graf::list* Graf::Dijkstra()
//{
//	//tab
//	int* colours = new int[size];
//	int* prev = new int[size];
//	int* weight = new int[size];
//	int* listonosz = new int[size];
//
//	int black = 2;
//	int grey = 1;
//	int id = 1;
//	int here;
//	int pom;
//	int j;
//
//
//	//print_id_Dijkstra(size);
//	set_array(colours, prev, weight, size);
//
//	//struktury
//	list* lista = NULL;
//	list* D = NULL;
//	node* p = new node;
//
//	//inicjalizacja
//	here = 1;
//	pom = 1;
//	j = 1;
//	//	int x = 1;
//	while (true)
//	{
//		j = 0; //zerujemy sprawdzenie stanu
//		p = ls[here]; //ładujemy nody dla danej listy
//		while (p)
//		{
//			//set val
//			if (colours[p->to] != 2)
//			{
//				colours[p->to] = 1;
//				if (weight[p->to] > (weight[here] + p->weight) || weight[p->to] == 0)
//				{
//					weight[p->to] = p->weight + weight[here];
//					prev[p->to] = here;
//				}
//
//				lista->add(p->to, lista); //dodajemy na listę do odwiedzenia
//
//			}
//			p = p->next;
//		}
//		colours[here] = 2; // ustawiamy node z wyczerpaną liczbą sąsiedztwa na czarno (odiwedzony) 
//		here = findMin(weight, size, colours); //przechodzimy do noda do którego droga jest najkrótsza       
//		finalexpo(colours, prev, weight, size, id); id++;
//		if (isAllBlack(size, colours, j)) break; //jeżeli wszystki nody odwiedzone kończymy zabawe
//	}
//
//
//
//
//	cout << "---------------------------------FINAL--------------------------------- " << endl;
//	finalexpo(colours, prev, weight, size, id);
//	return lista;
//}




//-----------------------------------------------
//void Graf::LE::sort(LE*& head)
//{
//	head->add(NULL, NULL, NULL, head);
//	LE* pom = new LE;
//	pom = head;
//	LE* pom2 = new LE;
//	int pomocniczy;
//	while (pom->next && pom->next->next)
//	{
//		if (pom->next->weight > pom->next->next->weight)
//		{
//			pom2 = pom->next->next;
//			pom->next->next = pom->next->next->next;
//			pom2->next = pom->next;
//			pom->next = pom2;
//		}
//		pom = pom->next;
//	}
//
//	pom = head;
//	head = head->next;
//	delete pom;
//}