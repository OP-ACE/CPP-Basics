#include <iostream>
#include <array>
 
int main(void) {
    std::array<float, 10> arr = {1, 2, 3, 4, 5};

    arr[2] = 98.4f;
 
    std::cout << "array values: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
 
    return 0;
}