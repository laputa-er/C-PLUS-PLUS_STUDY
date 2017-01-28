#include <iostream>
using namespace std;

class Student
{
public:
    Student()
    {
        cout << "Student()" << endl;
        m_pName = new char[20]; // 动态分配内存
    }

    //析构函数
    ~Student()
    {
        cout << "~Student()" << endl;
        delete []m_pName;
    }
    
private:
    char *m_pName;
};


int main(void)
{
    Student stu1;
}