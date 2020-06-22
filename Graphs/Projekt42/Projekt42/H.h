#pragma once
class Graf
{
public:

	struct node
	{
		node* next;
		int weight;
		int to;



	public:
		void Add_node(node*& array, int weight, int to );
		void print_node1(node* NODE, int i);
		
	};
	

	struct list
	{
		list* next;
		int val;

		static bool is_it_on_list(int value, list* root);
		void add(int value, list*& root);
		void print_list1(list* root);
		/*list* find_and_return(int value, list* root);*/
		
	};



	struct LE  // - lista krawędzi 
	{
		int from;
	    int to;
		int weight;
		LE*	next;


		//cons
		LE();

		//methods
		void fix(LE*& head);
		void add(int from, int to, int weight, LE*& head);
		void print(LE* head);
		void mergesort(LE*& head); void split(LE*source, LE *& front, LE*&back); LE* sortmerge(LE* a, LE* b);
		


		void K(LE*& head, int size);

	};

private:

	node **ls;  //lista somsiedztwa
	int size;

public:
//add
	///lista sąsiedztwa
	void AddDijkstraToLs();
	void AddWszerzToLs();
	///lista wierzchołków 
	void AddToLE(); 

//print
	void PRINT();
	void PRINTDIJKSTRA();
	
//sys
	list* Wszerz();
	void Dijkstra();

//cons
	Graf();

};
