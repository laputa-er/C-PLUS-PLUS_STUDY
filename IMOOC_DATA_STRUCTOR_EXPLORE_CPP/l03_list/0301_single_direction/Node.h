#ifndef NOOD_H
#define NOOD_H
#include <iostream>
using namespace std;

class Node 
{
public:
	int data;
	Node *next;
	void printNode();
};
#endif