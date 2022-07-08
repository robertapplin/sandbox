#include <iostream>
#include <string>
#include <utility>


struct MyString : public std::string {
    using std::string::string;

    MyString(const MyString &str) : std::string(str) {
        std::cout << "Actual: Copied '" << *this << "'\n" << std::endl;
    }
    MyString(MyString &&str) : std::string(std::move(str)) {
        std::cout << "Actual:  Moved '" << *this << "'\n" << std::endl;
    }
};

MyString returnRValue(MyString &&str) {
    return std::forward<MyString>(str);
}

const MyString &returnByReference(const MyString &str) {
    return str;
}

MyString returnByValue(const MyString &str) {
    return str;
}

int main() {
    // When the const/non-const lvalue exists in the same scope as the function call, it can be returned by reference
    std::cout << " &res = f(const lvalue) -> Ref" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Expected: Returned by reference\n" << std::endl;
    const MyString var1 = "var1";
    const MyString &res1 = returnByReference(var1);

    std::cout << " &res = f(lvalue) -> Ref" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Expected: Returned by reference\n" << std::endl;
    MyString var2 = "var2";
    const MyString &res2 = returnByReference(var2);

    // When the result of passing an lvalue is a non-reference variable, the returned reference is copied into the normal variable
    std::cout << " res = f(const lvalue) -> Ref" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Expected: Copied" << std::endl;
    const MyString var3 = "var3";
    const MyString res3 = returnByReference(var3);

    // When the return is by value, when passing an lvalue parameter, the lvalue is copied.
    std::cout << " &res = f(const lvalue) -> Val" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Expected: Copied" << std::endl;
    const MyString var4 = "var4";
    const MyString &res4 = returnByValue(var4);

    // Copy elision (return value optimization (RVO)) happens here to avoid an unnecessary double copy
    std::cout << " res = f(const lvalue) -> Val" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Expected: Copied" << std::endl;
    const MyString var5 = "var5";
    const MyString res5 = returnByValue(var5);

    // When there is an rvalue being passed, the lvalue parameter within the function must be copied as the lifetime of the parameter
    // of the function ends when the function returns. C++20 will move it out however! To get this in C++17, we need to forward it
    std::cout << " &res = f(rvalue) -> Val" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Expected: Copied (c++17), Moved (c++20)" << std::endl;
    const MyString &res6 = returnRValue(MyString{"var6"});

    return 0;
}