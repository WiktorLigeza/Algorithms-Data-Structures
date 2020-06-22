#include "H.h"



void Wzorce::start()
{
	int x;
	///s - ³añcuch znaków 
	string s;
	///p - ³añcuch wzorca 
	string p;

	
	s = "abababacaba";
	p = "ababaca";

	cout << "wybierz funkcje: " << endl << "1.Naiwna" << endl << "2.Rabina" <<endl <<"3.Automat"<< endl;  
	cin >> x;

	switch (x)
	{
	case 1: naiwny(p, s); break;
	case 2: rabina(p, s); break;
	case 3: automat(p, s); break;
	default: cout << "wrong number" << endl; break;
	}
	
}

int Wzorce::dlugosc(string p, string s)
{
	///s - ³añcuch znaków 
	is = 0;
	///p - ³añcuch wzorca 
	ip = 0;
 
	for each(char c in s)
	{
		is++;
	}
	for each(char c in p)
	{
		ip++;
	}
	cout << "dlugosc lancucha: " << is << endl;
	cout << "dlugosc wzorca: " << ip << endl;

	return is, ip;
}


//naiwny
void Wzorce::naiwny(string p, string s)
{
	dlugosc(p, s);

	for ( int i = 0; i < is; i++)
	{
		int j = 0;
		int x = i;
		while (s[x] == p[j])
		{
			x++;
			j++;
			if (j == ip)
			{
				cout << "tab[" << x - ip << "]" << endl; break; 
			}
		}
	}

}


//rabin karp
void Wzorce::rabina(string p, string s)
{
	dlugosc(p, s);

	int mod = is;
	int key;
	int tab[10000]; //tablica kluczy
	int hash;
	int num = 0;
	int sum = 0;

	

		//tablica kluczy 
	for (int i = 0; i < is; i++)
	{
		int x = i;
		for (int j = 0; j < ip ; j++)
		{
			num = s[x];
			sum += num;
			x++;
			if (x > is) { j = ip; }//breaking point
		}
		hash = sum % mod;
		tab[i] = hash;
		cout << "tab" << "[" << i << "] = " << hash << endl;
		sum = 0;
	}

	
	
		//klucz wzorca
	for (int j = 0; j < ip; j++)
	{
		num = p[j];
		sum += num;
	}
	key= sum % mod;
	cout <<"klucz: " << key << endl;
	
	for (int i =0; i < is ;i++)
	{
		if (tab[i] == key && naiwny_rabin(ip, i, p, s) )
		{ 
			cout << "tab[" <<i<<"]" << endl;
		}
	}

}

bool Wzorce::naiwny_rabin(int x, int y, string p, string s) //dlugosc stringow - x //miejsce do przeszukania - y
{
	int truecounter = 0;
	int i = y;
	int j = 0;



	while (s[i] == p[j])
	{
		truecounter++;
		i++;
		j++;
		if (i == y+x) { break; }
	}

	if (truecounter == x) { return true; }
	else { return false; }
}


//automat
void Wzorce::automat(string p, string s)
{
	//inicjalizacja

	dlugosc(p, s);
	int* tabA = new int[ip];
	int* tabB = new int[ip];
	int* tabC = new int[ip];
	int* state = new int[is];

	
	zero_array(tabA, tabB, tabC, state,is, ip);
	tabelastanowa(ip, p, tabA, tabB, tabC);
    pattern_finder(state, tabA, tabB, tabC, p, s);


	cout << endl;
	cout << endl;
	print_array(p, s, state, is);
}

void Wzorce::tabelastanowa(int ip, string p, int* tabA, int* tabB, int* tabC)
{
	string alphabet = "abc";
	int x;
	int y;
	int z;
	
	cout << endl;
	cout << "stan | a | b | c" << endl;


		for (int i = 0; i <= ip; i++)
		{
			check(p, i, alphabet, tabA, tabB, tabC);
			print_statemachine(tabA, tabB, tabC, i);
		}
	
		
}

void Wzorce::check(string p, int i,string alphabet, int* tabA, int* tabB, int* tabC)
{
	char test[15];
	int x;
	
			for (int k = 0; k <= i; k++)
			{
				test[k] = p[k];
			}

			for (int j = 0; j < 3; j++)//sprawdza dla ka¿dej litery alfabetu
			{
				test[i] = alphabet[j]; 
				
				x = ismatch(test, p, i);

				 if (alphabet[j] == 'a') { tabA[i] = x; }
				 if (alphabet[j] == 'b') { tabB[i] = x; }
				 if (alphabet[j] == 'c') { tabC[i] = x; }
			}

}

int Wzorce::ismatch(char* test, string p,int i)
{
	int val = 0;
	
	for (int x = 0; x <= i; x++)
	{
		if (p[x] == test[i]) // jezeli pierwa litera próbna sie zgadza sprawdzamy zgodnoœæ pozosta³ych
		{ 
			int y = x;
			int z = i;
			int v = 0;
			while (y > -1 && test[z] == p[y] )
			{
				v++;
				y--;
				z--;
			}
			if (v == x+1 || x == 0) //  je¿eli iloœæ zgodnoœci(v) jest odpowiednia(równa pozycji litery próbnej (i)) to iloœæ zgodnoœci stanowi(v) wartoœæ stanu(val)
			{
				val = v;
			}
		}
	}

	return val;
}

void Wzorce::pattern_finder(int* state, int* tabA, int* tabB, int* tabC,string p, string s)
{
	int j = 0; //obecny stan
	int x = 0; //obecny stan
	state[-1] = j;


	for (int i = 0; i < is; i++)
	{
		if (s[i] == 'a')
		{
			j = tabA[j];
		}
		if (s[i] == 'b')
		{
			j = tabB[j];
		}
		if (s[i] == 'c')
		{
			j = tabC[j];
		}
		state[i] = j;
		if (j == ip)
		{
			cout << endl << "pattern found at: " << i+1-ip << endl;
			x++;
		}
	}
	if (x == 0)
	{
		cout << endl << "pattern not found "  << endl;
	}
}



//tablice
void  Wzorce::print_statemachine(int* tabA, int* tabB, int* tabC, int i)
{

		cout << "------------------" << endl;
		cout <<"  "<< i << "  | " << tabA[i] << " | " << tabB[i] << " | " << tabC[i] << endl;
	
}

void  Wzorce::zero_array(int* tabA,int* tabB, int* tabC,int* state,int is, int ip)
{
	for (int i = 0; i <= ip; i++)
	{
		tabA[i] = 0;
	}


	for (int i = 0; i <= ip; i++)
	{
		tabB[i] = 0;
	}


	for (int i = 0; i <= ip; i++)
	{
		tabC[i] = 0;
	}

	for (int i = 0; i <= is; i++)
	{
		state[i] = 0;
	}
}

void Wzorce::print_array(string p, string s,int* state, int is)
{
	for (int i = -1; i < is; i++)
	{
		cout <<" | "<<i;
	}
	cout<<endl << "--------------------------------------------------"<< endl;
	
	cout << " | " << "- ";
	for (int i = 0; i < is; i++)
	{
		cout << " | " << s[i];
	}
	cout << endl << "--------------------------------------------------" << endl;
	
	cout << " | " << "- ";
	for (int i = 0; i < is; i++)
	{
		cout << " | " << state[i];
	}
	cout << endl << "--------------------------------------------------" << endl;
	

	cout << endl;
	cout << endl;
}

























//
//
//
//
//
//void Wzorce::tabelastanowa(int ip, string p, int* tabA, int* tabB, int* tabC)
//{
//	string alphabet = "abc";
//	int x;
//	int y;
//	int z;
//
//	cout << endl;
//	cout << "stan | a | b | c" << endl;
//
//
//	for (int i = 0; i <= ip; i++)
//	{
//		int j = 0;
//		x = i + 1;
//		for (int j = 0; j < 3; j++)
//		{
//			if (p[i] == alphabet[j])
//			{
//				if (alphabet[j] == 'a') { tabA[i] = x; }
//				if (alphabet[j] == 'b') { tabB[i] = x; }
//				if (alphabet[j] == 'c') { tabC[i] = x; }
//
//			}
//			else
//			{
//				check(p, j, i, alphabet, tabA, tabB, tabC);
//			}
//		}
//		check(p, alphabet[j], i, alphabet, tabA, tabB, tabC);
//		print_array(tabA, tabB, tabC, i);
//	}
//
//}
//
//void Wzorce::check(string p, int j, int i, string alphabet, int* tabA, int* tabB, int* tabC)
//{
//	char test[15];
//	int x;
//	if (i != 0)
//	{
//		for (int k = 0; k <= i; k++)
//		{
//			test[k] = p[k];
//		}
//
//		for (int j = 0; j < 3; j++)//sprawdza dla ka¿dej litery alfabetu
//		{
//			test[i] = alphabet[j];
//
//			x = ismatch(test, p, i);
//
//			if (alphabet[j] == 'a') { tabA[i] = x; }
//			if (alphabet[j] == 'b') { tabB[i] = x; }
//			if (alphabet[j] == 'c') { tabC[i] = x; }
//		}
//	}
//
//
//
//}
//
//int Wzorce::ismatch(char* test, string p, int i)
//{
//	int val = 0;
//
//	for (int x = 0; x <= i; x++)
//	{
//		if (p[x] == test[i]) // jezeli pierwa litera próbna sie zgadza sprawdzamy zgodnoœæ pozosta³ych
//		{
//			int y = x;
//			int v = 0;
//			while (y > -1 && test[y] == p[y])
//			{
//				v++;
//				y--;
//			}
//			if (v == x || v == i) //  je¿eli iloœæ zgodnoœci(v) jest odpowiednia(równa pozycji litery próbnej (i)) to iloœæ zgodnoœci stanowi(v) wartoœæ stanu(val)
//			{
//				val = v;
//			}
//		}
//	}
//
//
//
//
//	return val;
//}
//
//
//
//
//
//
//
//
//
//
//






//
//
//
//for (int y = x; y >= 0; y--)
//{
//	if (test[y] == p[y])
//	{
//
//	}
//}






//for (int x = i; x >= 0; x--)
//{
//	y++;
//	if (test[x] == p[0])
//	{
//		int v = 0;
//		for (int z = 0; z <= y; z++)
//		{
//			if (test[x - z] == p[z])
//			{
//				v++;
//			}
//			if (v >= y)
//			{
//				val = v;
//			}
//		}
//	}
//}








//{
//	for (int k = 0; k < i; k++)
//	{
//		test[k] = p[k];
//	}

//	for (int j = 0; j < 3; j++)
//	{
//		test[i] = alphabet[j];
//		
//		//ismatch();
//	}
//	cout << test;
//}