

// 为了区分是指向常量的指针还是const指针(表示指针本身是常量)

// 一个简便方法：从由往左读，遇到p就替换为“p is a”，遇到*就替换为“point to”，其余不变。

// const int * p ；// p is a point to int const ，p是一个指向常量的指针，指向的对象是一个常量，所以不能改变 *p（p指向内存地址）的值，但是p可以指向其它地址

// int * const p；// p is a const point to int, p是一个常量指针，指向int，所以不能改变指针本身p的值，但是可以改变p指向内存地址的值

 

// 根据Effective C++里总结的：

// 如果关键字const出现在星号左边, const * : 被指物  是常量

// 如果关键字const出现在星号右边，* const : 指针自身是常量

// 如果出现在星号两边，表示被指物和指针两者都是常量.



// // 事实上这个概念谁都有只是三种声明方式非常相似很容易记混。
// // Bjarne在他的The C++ Programming Language里面给出过一个助记的方法：
// // 把一个声明从右向左读
// // char  * const cp; ( * 读成 pointer to )
// // cp is a const pointer to char
// // const char * p;
// // p is a pointer to const char;
// // char const * p;
// // 同上因为C++里面没有const*的运算符，所以const只能属于前面的类型。
