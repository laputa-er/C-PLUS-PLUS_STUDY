#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string name, string phone)
{
	data.name = name;
	data.phone = phone;
}

void Node::printNode()
{
	cout << data << endl;
}