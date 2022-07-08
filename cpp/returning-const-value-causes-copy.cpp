// Note this is only the case for user-defined types. It doesn't matter if you return as const for built-in types
#include <iostream>
#include <string>
#include <utility>
#include <vector>


struct MyInt {

    MyInt(int i): m_int(i) {}

    MyInt(const MyInt &obj) : m_int(obj.m_int)  {
        std::cout << "Actual: Copied\n" << std::endl;
    }
    MyInt(MyInt &&obj) : m_int(std::move(obj.m_int)) {
        std::cout << "Actual:  Moved\n" << std::endl;
    }

private:
    int m_int;
};

MyInt getValue() {
    return MyInt(1);
;
}

const MyInt getConstValue() {
    return MyInt(1);
;
}

void insertLValue(MyInt &str) {
    std::vector<MyInt> vec;
    vec.push_back(str);
}

void insertString() {
    std::vector<MyInt> vec;
    vec.push_back(getValue());
}

void insertConstString() {
    std::vector<MyInt> vec;
    vec.push_back(getConstValue());
}

int main() {
    // Can't insert an l value reference into vec, so a copy of the value is made
    std::cout << " insert" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Expected: Copied" << std::endl;
    MyInt var1(1);
    insertLValue(var1);

    // When the return is by non-const value, the value can be moved into a vector
    std::cout << " insertString" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Expected: Moved" << std::endl;
    insertString();

    // When the return is by const value, the value gets copied into a vector. A const return type cannot be an lvalue as
    // explained here https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter08_014.html . 
    // This means its an rvalue that needs to be copied into a permanent memory location (you can't std::move i.e. static
    // cast to a reference of a temporary memory location)
    std::cout << " insertConstString" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Expected: Copied" << std::endl;
    insertConstString();

    return 0;
}