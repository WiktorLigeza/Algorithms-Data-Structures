#pragma once
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

class SS  //sorting system
{

	struct node
	{
		node* next;
		int val;

	public:
		void addToList(node*&, int);
		void delFromList(node*&);
		void printList(node*, int);
	};

	node** kubelek; //lista somsiedztwa


public:
	void start(int, int);
	void print(int);
	void kubelekToList( int);

	//kublekowe
	void kubelkowe(int*,int, int);
	void kubelkowe_bombel(node*&);

	//merge
	void split(node*, node*&, node*&);
	node* sortmerge(node*, node*);
	void mergesort(node*&);
};

