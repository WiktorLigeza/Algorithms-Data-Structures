#include "H.h"


void SS::start(int quantity, int size) //quantity - ilosc liczb , size - rozmiar kube³ków
{
	
	int* unsorted = new int[size];
	kubelek = new node*[size];
	int j;
	node* H = new node;
	H = NULL;
	clock_t start;
	clock_t finish;



	//cout << "unsorted array: " << endl;
	for (int i = 0; i < size; i++)
	{
		j = rand() % (quantity);
		unsorted[i] = j;
		H->addToList(H, j);
	}
	//cout << endl;


	for (int i = 0; i < size; i++)
	{
		kubelek[i] = NULL;     
	}



	cout << "kubelkowe:" << endl;

	start = ((clock()*10000) / CLOCKS_PER_SEC);
	cout << endl;
	kubelkowe(unsorted,quantity, size);
	finish = ((clock() * 10000) / CLOCKS_PER_SEC);
	cout << "czas:" << finish - start << endl;

	//print(size);


	cout << "merge:" << endl;
	//H->printList(H, 0);

	start = ((clock() * 10000) / CLOCKS_PER_SEC);
	cout << endl;
	mergesort(H);
	finish = ((clock() * 10000) / CLOCKS_PER_SEC);
	cout << "czas:" << finish - start << endl;

//	H->printList(H, 0);
}


//sortowanie
void SS::kubelkowe(int* unsorted, int quantity,int size)
{
	int j; 
	for (int i = 0; i < size; i++)
	{
		j = unsorted[i] / quantity ;
		kubelek[j]->addToList(kubelek[j], unsorted[i]);
		kubelkowe_bombel(kubelek[j]);
	}
}

void SS::kubelkowe_bombel(node*& head)
{
	head->addToList(head, 0);
	node* pom = head;
	node* pom2 = head;
	while (pom)
	{
		while (pom2 && pom2->next && pom2->next->next)
		{
			if (pom2->next->next->val < pom2->next->val)
			{
				node* pomocnik = pom2->next;
				pom2->next = pom2->next->next;
				pomocnik->next = pomocnik->next->next;
				pom2->next->next = pomocnik;
			}
			pom2 = pom2->next;
		}
		pom2 = head;
		pom = pom->next;
	}
	head->delFromList(head);
}

void SS::print(const int size)
{
	for (int i = 0; i < size; i++)
	{
		kubelek[i]->printList(kubelek[i], i);
	}
	kubelekToList(size);
}

void SS::kubelekToList(const int size)
{
	node* sorted = new node;
	sorted = NULL;

	for (int i = 0; i < size; i++)
	{
		node* p = kubelek[i];
		while (p)
		{
			sorted->addToList(sorted, p->val);
			p = p->next;
		}
	}

	sorted->printList(sorted, 0);
}

//lista
void SS::node::addToList(node*& H, int x)
{
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
}

void SS::node::delFromList(node*& H)
{
	node* p = H;
	H = H->next;
	delete p;
}

void SS::node::printList(node* H, int i)
{
	cout << "kubelek" << "[" << i << "]";
	while (H != NULL)
	{
		cout << "->" << H->val;
		H = H->next;
	}
	cout << endl;
}


//merge
void SS::split(node* source, node*& front, node*&back)
{
	node * fast;
	node * slow; //pomocnicze
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

SS::node* SS::sortmerge(node* a, node*b)
{
	node * result = NULL;

	if (a == NULL)
	{
		return (b);
	}
	else if (b == NULL)
	{
		return(a);
	}

	if (a->val <= b->val)
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

void SS::mergesort(node*& head)
{
	node *pom = head;
	node *a;
	node *b;

	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}
	split(head, a, b);

	mergesort(a);
	mergesort(b);

	head = sortmerge(a, b);
}


