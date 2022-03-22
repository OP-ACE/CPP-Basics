#include <iostream>

void set99( int&& n )
{
    std::cout << "n=" << n << std::endl;
    n = 99;
    std::cout << "n=" << n << std::endl;
}


int main()
{
    //! 对于非常量对象 x , 我可以更改也可以不更改
    int x = 1000;
    const int & const_ref_x = x;
    std::cout << const_ref_x << std::endl;

    int & non_const_ref_x = x;
    non_const_ref_x = 2000;
    std::cout << non_const_ref_x << std::endl;

    //! 但对于常量对象 y, 只能承诺不更改
    const int y = 123;
    const int & const_ref_y = y;
    std::cout << const_ref_y << std::endl;

    //int & non_const_ref_y = y; //! error, 提示 将 "int &" 类型的引用绑定到 "const int" 类型的初始值设定项时，限定符被丢弃

    //! 右值(临时对象等)可以用右值引用更改
    set99(1);

}