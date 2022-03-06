#include <iostream>

class Resouce                                 //* ----- [经验] 最简单的类, 空类
{
    public:                                   //! ----- [错误] 忘记把构造函数写到public中
    Resouce()
    {
        std::cout << "Resouce constructed ! \n";
    }
    ~Resouce()
    {
        std::cout << "Resource  destroyed ! \n";
    }
};

void someFunction()
{
    Resouce *ptr = new Resouce();             //! ------ [错误] 写成了 new(Resource)

    delete ptr;
};

int main()
{
    someFunction();
    return 0;
}
