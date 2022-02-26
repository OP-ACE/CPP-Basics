#include <iostream>
#include <array>

using namespace std;
 
int main(void) {
    std::array<int, 10> A;

    std::cout << "------------------ A array values: \n";
    for (auto it =  A.begin(); it !=  A.end(); ++it) {
        std::cout << *it << endl;
    }


    std::array<float, 10> B = {1, 2, 3, 4, 5};
    B[2] = 98.4f;
 
    std::cout << "------------------ B array values: \n";
    for (auto it = B.begin(); it != B.end(); ++it) {
        std::cout << *it << endl;
    }
    std::cout << std::endl;


    int i0 = int();
    float f0 = float();
    string s0 = string();

    cout << "i0 = " << i0 << endl;
    cout << "f0 = " << f0 << endl;
    cout << "s0 = " << s0 << endl;
 
    return 0;
}