#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/*********************
* 数据的封装
* 定义一个 Student 类，含有以下信息：
* 1. 姓名：name
* 2. 性别：gender
* 3. 学分（只读）：score
* 4. 学习：study
***********************/

class Student
{
public:
    // m_strName
    void setName(string _name)
    {
        m_strName = _name;
    }
    string getName()
    {
        return m_strName;
    }

    // m_strGender
    void setGender(string _gender)
    {
        m_strGender = _gender;
    }
    string getGender()
    {
        return m_strGender;
    }

    // m_iScore
    int getScore()
    {
        return m_iScore;
    }


    void initScore()
    {
        m_iScore = 0;
    }

    void study(int _score)
    {
        m_iScore += _score;
    }
private:
    string m_strName;
    string m_strGender;
    int m_iScore;
};

int main(void)
{
    Student stu;
    stu.initScore();

    stu.setName("mengxiang");
    stu.setGender("boy");
    stu.study(5);
    stu.study(3);

    cout << stu.getName() << " " << stu.getGender() << endl;

    return 0;
}