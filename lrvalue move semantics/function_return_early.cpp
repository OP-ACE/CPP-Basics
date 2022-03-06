#include <iostream>

class Resource
{
    public:                                    //! ----- [错误] 再次丢了 public
    Resource()
    {
        std::cout << "Resource constructed !";
    };

    ~Resource()
    {
        std::cout << "Resource    destoyed !";
    }
};



void someFunction()                           //! ---- [错误] 丢了返回类型 void
{
    Resource * ptr = new Resource(); 

    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
        return;
    
    delete ptr;
};

int main()
{
    someFunction();

    return 0;
}