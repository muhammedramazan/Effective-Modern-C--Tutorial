#include <iostream>
#include <type_traits>

template <typename T>
void checkReferenceType(const T&&) {
    if constexpr (std::is_lvalue_reference<T>::value) {
        std::cout << "T&& is an lvalue reference" << std::endl;
    } else if constexpr (std::is_rvalue_reference<T>::value) {
        std::cout << "T&& is an rvalue reference" << std::endl;
    } else {
        std::cout << "T&& is neither lvalue nor rvalue reference" << std::endl;
    }
}

template <typename T>
void inspectType(const T& arg) {
    // Check if arg is an lvalue reference
    std::cout << "Is lvalue reference: " << std::is_lvalue_reference<T>::value << '\n';
    // Check if arg is an rvalue reference
    std::cout << "Is rvalue reference: " << std::is_rvalue_reference<T>::value << '\n';
}

int main() {
    int a = 42;
    int&& rvalueRef = 10;

    std::cout << "Checking lvalue reference:" << std::endl;
    inspectType(a);

    std::cout << "\nChecking rvalue reference:" << std::endl;
    inspectType(rvalueRef);

    std::cout << "\nChecking universal reference:" << std::endl;
    checkReferenceType(42); // Pass an rvalue
    checkReferenceType(a);  // Pass an lvalue

    return 0;
}
