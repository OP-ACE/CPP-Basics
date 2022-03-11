#include <iostream>

bool isOdd_by_ref(int &n){
    if(n/2 == 0){
        return false;
    }else{
        return true;
    }
}
bool isOdd_by_value(int n){  //改为值传递
    if(n/2 == 0){
        return false;
    }else{
        return true;
    }
}

bool isOdd_by_const_ref(const int &n){  //改为常引用
    if(n/2 == 0){
        return false;
    }else{
        return true;
    }
}


template <typename T>
const T& get_min_by_const_ref(const T& a, const T& b)
{
    return a < b ? a : b;
}

// template <typename T>
// T& get_min_by_ref(const T& a, const T& b)
// {
//     return a < b ? a : b;
// }


int main(){
    int a = 100;

    isOdd_by_ref(a);  //正确
    isOdd_by_value(a);  //正确
    isOdd_by_const_ref(a);  //正确

    // isOdd_by_ref(a + 9);  //错误
    isOdd_by_value(a + 9);  //正确
    isOdd_by_const_ref(a + 9);  //正确

    // isOdd_by_ref(27);  //错误
    isOdd_by_value(27);  //正确
    isOdd_by_const_ref(27);  //正确

    // isOdd_by_ref(23 + 55);  //错误
    isOdd_by_value(23 + 55);  //正确
    isOdd_by_const_ref(23 + 55);  //正确

    int x = 10, y = 2;
    auto const_ref_out = get_min_by_const_ref(x, y + 1);
    std::cout << const_ref_out << '\n';

    return 0;
}
