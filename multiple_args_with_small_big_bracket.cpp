#include <iostream>
using namespace std;

class IntList {
public:
	IntList(int a, int b, int c) 
	{ cout << "[ " << a << " , " << b << " , " << c << "]" << endl; }
};

int main()
{
	IntList it1( 1, 2, 3 );
	IntList it2({2, 3, 4});
	IntList it3{ 5, 6, 7 };

	return 0;
}