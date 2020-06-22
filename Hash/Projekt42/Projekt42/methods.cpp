#include "H.h"


//list
void H::list::add_list(string value, list*& head)
{
	list* p = new list;
	p->val = value;
	p->next = head;
	head = p;
}
void H::list::del_list(list*& head)
{
	if (head != NULL)
	{
		list* p = head;
		head = head->next;
		delete p;
	}
}
void  H::list::print_list(list* head, int i)
{
	cout << "tl" << "[" << i << "]";
	while (head)
	{
		cout << "->" << head->val;
		head = head->next;
	}
	cout << "->NULL" << endl;
}






//hash
int  H::hash(int size, string imie)
{
	int i;
	int x = 0;
	int m = size;
	for each (char letter in imie)
	{
		int num;
		if (letter >= 'A' && letter <= 'Z')
		{
			num = letter - 'A' + 1;
		}
		else if (letter >= 'a' && letter <= 'z')
		{
			num = letter - 'a' + 1;
		}
		x += num;
	}
	i = x % m;
	//cout << x <<" mod "<<m<<" = "<<i << endl;
	return i;
}

//chain
void H::add_chain()
{
	int index;
	string imie;
	tl = new list*[size];
	//string* ludzie = new string[size];

	//inicjalizacja
	for (int i = 0; i < size; i++)
	{
		tl[i] = NULL;
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj imie:" << endl;
		cin >> imie;
		index = hash( size, imie); //zwracamy index do przypisania 
		tl[index]->add_list(imie, tl[index]);
		
	}
	show_chain();
}
void H::show_chain()
{
	cout << endl;
	cout << endl;
	cout << "PRINT CHAIN: " << endl;
	for (int i = 0; i < size; i++)
	{
		tl[i]->print_list(tl[i], i);
	}
	cout << endl;
	cout << endl;
}


//open 
void H::add_open()
{
	int index;
	string imie;
	
	

	for (int i = 0; i < 1; i++)
	{
		cout << "Podaj imie:" << endl;
		cin >> imie;
		index=hash(size, imie);

		insert_open(index,imie);
		
	}

	show_open();
	cout << endl;
	cout << endl;
}
void H::show_open()
{

	for (int i = 0; i < size; i++)
	{
		cout << "tab" << "[" << i << "]" << ludzie[i] << endl;
	}


}
int H::search_open()
{
	int index;
	int i;
	int breaker = 0;
	string imie;

	cout << "what record do you want to search for?" << endl;
	cin >> imie;
	index = hash(size, imie);
	i = find_open(index, imie,size,breaker);

	if (i == -1) { cout << "not found " << endl; return -1; }
	cout << "found record: tab" << "[" << i << "]" << ludzie[i] << endl << endl;

	return i;
}
void H::del_open()
{
	cout << "DELETION:" << endl;
	int index = search_open();
	if (index == -1) { cout << "try again" << endl; del_open(); return; }
	ludzie[index] = "deleted";
	show_open();

}
///help_open
void H::insert_open(int index,string imie)
{
	if (ludzie[index] == "" || ludzie[index] == "deleted")
	{
		ludzie[index] = imie;
		return;
	}
	else
	{
		index++;
		insert_open(index, imie);
	}
}
int H::find_open(int index, string imie, int size, int breaker )
{
	if (ludzie[index] == imie)
	{
		return index;
	}
	else
	{
		
		if (breaker == size)
		{ 
			return -1;
		}
		breaker++;

		index++;
		index = find_open(index, imie,size, breaker);
	}
	return index;
	
}







H::H()
{
	ludzie = new string[size];
}


///BACKUP

//void hash(string* tab, int size, string imie)
//{
//	int i;
//	int x = 0;
//	int m = size;
//	for each (char letter in imie)
//	{
//		int num;
//		if (letter >= 'A' && letter <= 'Z')
//		{
//			num = letter - 'A' + 1;
//		}
//		else if (letter >= 'a' && letter <= 'z')
//		{
//			num = letter - 'a' + 1;
//		}
//		x += num;
//	}
//	i = x % m;
//
//
//	//cout << x <<" mod "<<m<<" = "<<i << endl;
//
//	tab[i] = imie;
//}
//void add()
//{
//	int size = 13;
//	string imie;
//	string* ludzie = new string[size];
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Podaj imie:" << endl;
//		cin >> imie;
//		hash(ludzie, size, imie);
//	}
//	show(ludzie, size);
//}
//void show(string* ludzie, int size)
//{
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << "id: " << i << ". " << ludzie[i] << endl;
//	}
//}