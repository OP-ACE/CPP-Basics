#include <iostream>
using namespace std;

class MyClass

{

public:
    MyClass()

    {

        cout << "Construction MyClass." << this << endl;
    }

    ~MyClass()

    {

        imember = 0;

        cout << "Destruction MyClass." << this << endl;
    }

    int imember;
};


int main()
{
    MyClass *fPtr1 = new MyClass();

    char x[sizeof(MyClass)];

    // 由于定位new分配的内存并不是“新分配”的，而是原先就有的。所以不能使用delete来释放该内存，而是要通过析构函数来释放资源。
    MyClass *fPtr2 = new (&x[0]) MyClass;
    fPtr2->~MyClass();
}