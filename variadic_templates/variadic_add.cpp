#include <iostream>


namespace {

int add(int a) {
    return a;
}

// A variadic template using recursive parameter unpacking
template <typename Arg, typename... Args>
int add(Arg a, Args &&...others) {
    return a + add(others...);
}

}

int main(){
    std::cout << "Add result:\n";
    std::cout << add(1, 4, 9) << std::endl;
    return 0;
}
