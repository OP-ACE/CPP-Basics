//! //////////////////////////////////////////////////////////////////////// 1
// // C++ program to illustrate the placement new operator
// #include<iostream>
// using namespace std;

// int main()
// {
// 	// buffer on stack
// 	unsigned char buf[sizeof(int)*2] ;

// 	// placement new in buf
// 	int *pInt = new (buf) int(3);

// 	int *qInt = new (buf + sizeof (int)) int(5);
// 	int *pBuf = (int*)(buf+0) ;
// 	int *qBuf = (int*) (buf + sizeof(int));
// 	cout << "Buff Addr			 Int Addr" << endl;
// 	cout << pBuf <<"			 " << pInt << endl;
// 	cout << qBuf <<"			 " << qInt << endl;
// 	cout << "------------------------------" << endl;
// 	cout << "1st Int			 2nd Int" << endl;
// 	cout << *pBuf << "						 "
// 		<< *qBuf << endl;

// 	return 0;
// }

//! //////////////////////////////////////////////////////////////////////// 2

// // C++ program to illustrate the placement new operator
// #include<iostream>
// using namespace std;
// int main()
// {
// 	// initial value of X
// 	int X = 10;

// 	cout << "Before placement new :" << endl;
// 	cout << "X : " << X << endl;
// 	cout << "&X : " << &X << endl;

// 	// Placement new changes the value of X to 100
// 	int *mem = new (&X) int(100);

// 	cout << "\nAfter placement new :" << endl;
// 	cout << "X : " << X << endl;
// 	cout << "mem : " << mem << endl;
// 	cout << "&X : " << &X << endl;

// 	return 0;
// }


//! //////////////////////////////////////////////////////////////////////// 3
// C++ program to illustrate using destructor for
// deleting memory allocated by placement new
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class Complex
{
private:
	double re_, im_;
public:
	// Constructor
	Complex(double re = 0, double im = 0): re_(re), im_(im)
	{
		cout << "Constructor : (" << re_ << ", " << im_ << ")" << endl;
	}

	// Destructor
	~Complex()
	{
		cout << "Destructor : (" << re_ << ", " << im_ << ")" << endl;
	}

	double normal()
	{
		return sqrt(re_*re_ + im_*im_);
	}

	void print()
	{
		cout << "|" << re_ <<" +j" << im_ << " | = " << normal() << endl;
	}
};

// Driver code
int main()
{
	// buffer on stack
	unsigned char buf[100];

	Complex* pc = new Complex(4.2, 5.3);
	Complex* pd = new Complex[2];

	// using placement new
	Complex *pe = new (buf) Complex(2.6, 3.9);

	// use objects
	pc -> print();
	pd[0].print();
	pd[1].print();
	pe->print();

	// Release objects
	// calls destructor and then release memory
	delete pc;

	// Calls the destructor for object pd[0]
	// and then release memory
	// and it does same for pd[1]
	delete [] pd;

	// No delete : Explicit call to Destructor.
	pe->~Complex();

	return 0;
}



//! //////////////////////////////////////////////////////////////////////// 4
// // C++ program to illustrate segmentation fault
// // while using placement new operator
// #include<iostream>
// using namespace std;

// int main()
// {
// 	// Fine
// 	int i = 10;
// 	int *ipt = &i ;
// 	int *i1 = new(ipt) int(9) ;

// 	// Incorrect as ip may not
// 	// be a valid address
// 	int *ip;
// 	int *i2 = new(ip) int(4) ;

// 	// Fine
// 	void *vd = &i;
// 	int *i3 = new(vd) int(34) ;

// 	// Incorrect as x is not an address
// 	int x;
// 	int *i5 = new(x) int(3) ;

// 	return 0;
// }
