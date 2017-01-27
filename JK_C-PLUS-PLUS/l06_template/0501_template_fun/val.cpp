#include <iostream>
using namespace std;

template <int size>
void display()
{
	cout << size << endl;
}

int main(void)
{
	display<10>();
	return 0;
}