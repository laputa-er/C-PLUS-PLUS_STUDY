#include <string>
using namespace std;
class Teacher
{
public:
    // m_strName
    void setName(string _name);
    string getName();

    // m_strGender
    void setGender(string _gender);
    string getGender();

    // m_iAge
    void setAge(int _age);
    int getAge();

    void teach();
private:
    string m_strName;
    string m_strGender;
    int m_iAge;
};

