// !--------------------------------------------------------------------------
// !!!!!!!!!!!!!!!!!!!!! 父类对象 和 子类对象 之间的 值传递, 引用传递, 指针传递
// ! -------------------------------------------------------------------------
#include <iostream>

using namespace std;

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    virtual const char* getName() const { return "Derived"; }
};

int main()
{
    Derived d1{ 5 };
    std::cout << "d1 is a " << d1.getName() << " and has value " << d1.getValue() << '\n';

    Base& ref{ d1 };
    std::cout << "Asssign_d1_to_BaseRef is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Base* ptr{ &d1 };
    std::cout << "Asssign_d1_to_BasePtr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';
    
    std::cout << "--------------------  \n";

    Derived d2{ 12 };
    Base b2{ d2 };     // ! ---------------------------- 001 值传递不彻底, A = B, 只是把B的值传给了A, A的值等于B的值, 但A不是B

    std::cout << "b2 (Base b2{ d2 }) is a " << b2.getName()  << " and has value " << b2.getValue()  << "\n\n";

    Base b3(9);
    Derived d3(34);    // ! ---------------------------- 002 值传递不彻底, 只是把d3的一部分给了b3, b3不是d3
    b3 = d3;          

    Base* b4;
    Derived d4(56);
    b4 = &d4;          // ! ---------------------------- 003 引用很彻底, 可完全代替从而修改被引用对象

    Derived d5(78);
    Base& b5 = d5;     // ! ---------------------------- 004 指针很彻底, 可完全代替从而修改被引用对象

    std::cout << "d3 is a                 " << d3.getName()  << " and has value " << d3.getValue()  << "\n\n";
    std::cout << "d4 is a                 " << d4.getName()  << " and has value " << d4.getValue()  << "\n\n";
    std::cout << "d5 is a                 " << d5.getName()  << " and has value " << d5.getValue()  << "\n\n";

    std::cout << "b3 (b3 =  d3) is a      " << b3.getName()  << " and has value " << b3.getValue()  << "\n"  ;
    std::cout << "b4 (b4 = &d4) is a      " << b4->getName() << " and has value " << b4->getValue() << "\n"  ;
    std::cout << "b5 (Base& b5 = d5) is a " << b5.getName()  << " and has value " << b5.getValue()  << "\n"  ;
    

    return 0;
}