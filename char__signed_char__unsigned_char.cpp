// C++ program to illustrate the placement new operator
#include<iostream>
using namespace std;

int main()
{
	// buffer on stack
	unsigned char buf[sizeof(int)*2] ;
    cout << "buf = " << buf << endl;

	// placement new in buf
	int *pInt = new (buf) int(3);

	int *qInt = new (buf + sizeof (int)) int(5);
	int *pBuf = (int*)(buf+0) ;
	int *qBuf = (int*) (buf + sizeof(int));
	cout << "Buff Addr			 Int Addr" << endl;
	cout << pBuf <<"			 " << pInt << endl;
	cout << qBuf <<"			 " << qInt << endl;
	cout << "------------------------------" << endl;
	cout << "1st Int			 2nd Int" << endl;
	cout << *pBuf << "						 "
		<< *qBuf << endl;

	return 0;
}

// If you are using character types for text, use the unqualified char:

// it is the type of character literals like 'a' or '0' (in C++ only, in C their type is int)
// it is the type that makes up C strings like "abcde"

// If you are using character types as numbers, use:

// signed char, which gives you at least the -127 to 127 range. (-128 to 127 is common)
// unsigned char, which gives you at least the 0 to 255 range.

// 在C中，默认的基础数据类型均为signed，现在我们以char为例，说明(signed) char与unsigned char之间的区别 

// 首先在内存中，char与unsigned char没有什么不同，都是一个字节，唯一的区别是，char的最高位为符号位，因此char能表示-128~127, unsigned char没有符号位，因此能表示0~255，这个好理解，8个bit，最多256种情况，因此无论如何都能表示256个数字。

// 在实际使用过程种有什么区别呢？

// 主要是符号位，但是在普通的赋值，读写文件和网络字节流都没什么区别，反正就是一个字节，不管最高位是什么，最终的读取结果都一样，只是你怎么理解最高位而已，在屏幕上面的显示可能不一样。

// 但是我们却发现在表示byte时，都用unsigned char，这是为什么呢？

// 首先我们通常意义上理解，byte没有什么符号位之说，更重要的是如果将byte的值赋给int，long等数据类型时，系统会做一些额外的工作。

// 如果是char，那么系统认为最高位是符号位，而int可能是16或者32位，那么会对最高位进行扩展（注意，赋给unsigned int也会扩展）

// 而如果是unsigned char，那么不会扩展。

// 这就是二者的最大区别。

// 同理可以推导到其它的类型，比如short， unsigned short。等等

