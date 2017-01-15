#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(void)
{
    string name;
    cout << "Please input your name:";
    getline(cin, name);
    if(name.empty())
    {
        cout << "input is null." << endl;
        return 1;
    }
    if(name == "imooc")
    {
        cout << "you are a administractor" << endl;
    }
    cout << "hello " + name << endl;
    cout << "your name length:" << name.size() << endl;
    cout << "your name first letter is:" << name[0] << endl;

    return 0;
}