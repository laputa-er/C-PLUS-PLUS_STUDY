#ifndef NOOD_H
#define NOOD_H
#include "Person.h"
#include <string>
using namespace std;

class Node 
{
public:
	Node(string name = "Harry", string = "12345");
	Person data;
	Node *next;
	void printNode();
};
#endif