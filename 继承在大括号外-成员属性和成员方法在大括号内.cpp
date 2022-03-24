#include <iostream>
#include <string>

class Person
{
public:
    std::string m_name{}; //! 成员变量 m_name
    int m_age{};          //! 成员变量 m_age

    Person(const std::string& name = "", int age = 0)
        : m_name{name}, m_age{age}
    {}

    const std::string& getName() const 
    { return m_name; }

    int getAge() const 
    { return m_age; }

};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
//! ------------------------------------- 继承关系 在 大括号 外
{
public:
    double m_battingAverage{}; //! 成员属性 在 大括号 内
    int m_homeRuns{};          //! 成员属性 在 大括号 内

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0) //! 成员方法 在 大括号 内
       : m_battingAverage{battingAverage}, m_homeRuns{homeRuns}
    {
    }
};

int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe{};
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class

    return 0;
}