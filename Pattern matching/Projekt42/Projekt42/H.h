#pragma once

#include <iostream>
#include <string>

using namespace std;



class Wzorce
{
public:
	void start();
	int is, ip;

	void print_statemachine(int*, int*, int*, int);
	void zero_array(int*, int*, int*,int*,int, int);
	void print_array(string, string , int*, int);


	void tabelastanowa(int, string, int*, int*, int*);
	int ismatch(char*,string, int);
	void check(string, int,string, int*, int*, int*);
	void pattern_finder(int*, int*, int*, int*,string, string);

private:
	int dlugosc(string, string);
	void naiwny(string, string);
	void rabina(string, string);
	bool naiwny_rabin(int, int, string, string);
	void automat(string, string);
	

};