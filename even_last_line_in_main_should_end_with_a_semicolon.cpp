#include <iostream>
using namespace std;

void Twice(int a){ cout << a *2 << endl; }


int main(){
    cout << "--------------" << endl;
    cout << "Second line." << endl;
    cout << "Third line."  << endl;
    cout << "Even I am the last line in main, I should be ended with a semicolon \" ; \".";
    Twice(Twice(2));
}