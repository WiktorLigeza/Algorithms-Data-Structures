#pragma once
#include <iostream>
#include <string>

using namespace std;

class H
{
public:
	struct list
	{
		list* next;
		string val;

		void add_list(string, list*&);
		void del_list(list*&);
		void print_list(list*, int );
		
	};

	list **tl; //tablica list 
	int size = 4;
	string* ludzie;

	//hash
	int  hash(int, string );

	//chain
	void add_chain();
	void show_chain();

	//open
	void add_open();
	void show_open();
	int search_open();
	void del_open();
	///help_open
	void insert_open(int, string);
	int find_open(int,string,int,int);

	

	//open

	H();


};


