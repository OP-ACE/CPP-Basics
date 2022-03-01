#include<iostream>
#include<string>
using namespace std;

//声明Person类
template<class T1,class T2>
class Person;

//!----------------------------------------- 001 全局函数类外实现
//不用加作用域
//提前让编译器知道全局函数
template<class T1,class T2>
void ex_show(Person<T1,T2>p)
{
    cout<<"ex print : name : "<< p.m_Name << endl;
    cout<<"ex print : age  : "<< p.m_Age  << endl;
}

//!----------------------------------------- 001 全局函数类外实现
template<class T1,class T2>
class Person
{
    //全局函数 全局函数作为友元 类内实现
    friend void in_show(Person<T1,T2>p)
    {
        cout<<"in name: "<<p.m_Name<<endl;
        cout<<"in age:  "<<p.m_Age<<endl;
    }

    //全局函数 类外实现
    //加空模板参数列表 表明这是一个函数模板而非普通函数
    // friend void ex_show<>(Person<T1,T2>p);
    void ex_show<>(Person<T1,T2>p);

public:
    Person(T1 name,T2 age)
    {
        this -> m_Name = name;
        this -> m_Age  = age;
    }

// private:
    T1 m_Name;
    T2 m_Age;
};

void test_in_show()
{
    Person<string,int> p1("Tom",18);
    in_show(p1);
}

void test_ex_show()
{
    Person<string,int> p2("Amy",10);
    ex_show(p2);
}

int main()
{
    test_in_show();
    test_ex_show();
    return 0;
}

