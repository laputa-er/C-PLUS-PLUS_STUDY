#include <iostream>
using namespace std;

class Student
{
public:
    Student()
    {
        cout << "Student" << endl;
    }
    // 拷贝构造函数
    Student(const Student &stu)
    {
        cout << "Student（const Student &stu)" << endl;
    }
private:
    string m_strName;
};


int main(void)
{
    // 调用构造函数 Student()
    Student stu1; 

    // 调用拷贝构造函数
    Student stu2 = stu1;
    Student stu3(stu1);
}