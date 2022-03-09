#include <iostream>

// Same as above
template <typename T>
class Auto_ptr1
{
    T *m_ptr;

public:
    Auto_ptr1(T *ptr = nullptr)
        : m_ptr(ptr)
    {
    }

    ~Auto_ptr1()
    {
        delete m_ptr;
    }

    T &operator*() const { return *m_ptr; }
    T *operator->() const { return m_ptr; }
};

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

void passByValue(Auto_ptr1<Resource> res)
{
}

Auto_ptr1<Resource> generateResource()
{
    Resource* r{new Resource()};
    return Auto_ptr1<Resource>(r);
    // Auto_ptr1<Resource> s(r);
    // return s;
    //! new的是堆中的一块空间，栈中的指针变量指向这块空间。指针变量过了作用域，不再指向堆空间。
    //! new创建出来的内存空间是不会被销毁的，因为它是在堆上创建的。而指针变量是会被销毁的，因为它是在栈上创建的。
    /*  栈区（stack）       由编译器自动分配释放，存放函数局部变量值，参数值
        堆区（heap）        人为分配释放，如果不人为释放将在程序结束后由操作系统回收，分配方式类似于链表
        全局静态区（static） 全局变量以及静态变量，程序结束后有OS释放
                           初始化的全局变量
                           未初始化的全局变量
        文字常量区           存放常量字符串
        代码区              存放程序的二进制代码
    */

};

int main()
{
    Auto_ptr1<Resource> r = generateResource();
    // Auto_ptr1<Resource> res1(new Resource());
    // passByValue(res1);
    // Auto_ptr1<Resource> res2(res1);
    //! Alternatively, don't initialize res2 and then assign res2 = res1;

    return 0;
}