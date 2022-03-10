#include <iostream>

class MyClass
{
private:
    int counter;
public:
    void Foo()
    { 
        std::cout << "Foo" << std::endl;    
    }

    void Foo() const
    {
        std::cout << "Foo const" << std::endl;
    }

    // void Foo()
    // {
    //     counter++; //this works
    //     std::cout << "Foo" << std::endl;    
    // }

    // void Foo() const
    // {
    //     counter++; //this will not compile
    //     std::cout << "Foo const" << std::endl;
    // }

};

int main()
{
    MyClass cc;
    const MyClass& ccc = cc;
    cc.Foo();
    ccc.Foo();
}

