#include <string>
using namespace std;
class Teacher
{
public:
    Teacher();
    Teacher(string name, int age = 20);

    // m_strName
    void setName(string _name);
    string getName();

    // m_iAge
    void setAge(int _age);
    int getAge();

    void teach();
private:
    string m_strName;
    int m_iAge;
};

