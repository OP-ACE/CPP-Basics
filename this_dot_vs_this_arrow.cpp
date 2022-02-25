#include <iostream>
 
using namespace std;
 
class Dog
{
public:
	int id;
 
	void say_id() 
	{
		cout << "My id is "<<id << "\n\n" ;
	}
};
 
int main() {

    cout << "\n" ;

    cout << "foo->bar() == (*foo).bar()" << "\n\n";
	
    cout << "----------------------- obj.dat or obj.memfunc" << "\n\n";

    Dog dog;
	
    dog.id = 123;
	
    dog.say_id();

    
    cout << "----------------------- objPtr->dat or objPtr->memfunc" << "\n\n";

	Dog * dogPtr; 

	dogPtr = &dog;

    dogPtr -> say_id();   // ! ------------------------------------- 001.  dogPtr->id, dogPtr->say_id()
                          // ! dogPtr _> say_id() == dog.say_id()
	(*dogPtr).say_id();   // ! dogPtr -> id == dog.id

	
 
	dogPtr->id = 456;   // this is equal to (*y).number = 456;
	dogPtr->say_id();
}