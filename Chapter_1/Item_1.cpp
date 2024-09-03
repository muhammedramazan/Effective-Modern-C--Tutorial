// template<typename T>
// void f(ParamType param);
// f(expr); // call f with some expression

// There are three cases:
// case 1
// • ParamType is a pointer or reference type, but not a universal reference.
// (Univer‐ sal references are described in Item 24. At this point, all you need
// to know is that they exist and that they’re not the same as lvalue references
// or rvalue references.)
// case 2
// • ParamType is a universal reference.
// case 3
// • ParamType is neither a pointer nor a reference.

#include <iostream>
#include <typeinfo>
// case1 : ParamType is a Reference or Pointer, but not a Universal Reference

template <typename T>
void f_reference(T& param) {
  std::cout << "f_reference T Type -> " << typeid(T).name() << " refrence -> "
            << std::boolalpha << std::is_reference<T>::value << " const -> "
            << std::boolalpha
            << std::is_const<typename std::remove_reference<T>::type>::value
            << std::endl;
  std::cout << "T& param" << std::endl;
  std::cout << "f_reference param Type -> " << typeid(decltype(param)).name()
            << " refrence -> " << std::boolalpha
            << std::is_reference<decltype(param)>::value << " const -> "
            << std::boolalpha
            << std::is_const<
                   typename std::remove_reference<decltype(param)>::type>::value
            << std::endl;
}

template <typename T>
void f_const_reference(const T& param) {
  std::cout << "f_const_reference T Type -> " << typeid(T).name()
            << " refrence -> " << std::boolalpha << std::is_reference<T>::value
            << " const -> " << std::boolalpha
            << std::is_const<typename std::remove_reference<T>::type>::value
            << std::endl;
  std::cout << "const T& param" << std::endl;
  std::cout << "f_const_reference param Type -> "
            << typeid(decltype(param)).name() << " refrence -> "
            << std::boolalpha << std::is_reference<decltype(param)>::value
            << " const -> " << std::boolalpha
            << std::is_const<
                   typename std::remove_reference<decltype(param)>::type>::value
            << std::endl;
}

// param is a reference
template <typename T>
void f_pointer(T* param) {
  std::cout << "f_pointer T Type -> " << typeid(T).name() << " pointer -> "
            << std::boolalpha << std::is_pointer<T>::value << " const -> "
            << std::boolalpha
            << std::is_const<typename std::remove_pointer<T>::type>::value
            << std::endl;
  std::cout << "T* param" << std::endl;
  std::cout << "f_pointer param Type -> " << typeid(decltype(param)).name()
            << " pointer -> " << std::boolalpha
            << std::is_pointer<decltype(param)>::value << " const -> "
            << std::boolalpha
            << std::is_const<
                   typename std::remove_pointer<decltype(param)>::type>::value
            << std::endl;
}

// Case 2: ParamType is a Universal Reference
template <typename T>
void f_universal(T&& param) {
  if constexpr (!std::is_const<
                    typename std::remove_reference<T>::type>::value) {
    param = 1234;
  }
  if constexpr (std::is_rvalue_reference<T>::value) {
    std::cout << "-------" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "-------" << std::endl;
  }
  std::cout << "T&& param" << std::endl;
  std::cout << "f_universal T Type -> " << typeid(T).name()
            << " lvalue reference -> " << std::boolalpha
            << std::is_lvalue_reference<T>::value << " rvalue reference -> "
            << std::boolalpha << std::is_rvalue_reference<T>::value
            << " const -> " << std::boolalpha
            << std::is_const<typename std::remove_reference<T>::type>::value
            << std::endl;

  std::cout << "f_universal param Type -> " << typeid(decltype(param)).name()
            << " lvalue reference -> " << std::boolalpha
            << std::is_lvalue_reference<decltype(param)>::value
            << " rvalue reference -> " << std::boolalpha
            << std::is_rvalue_reference<decltype(param)>::value << " const -> "
            << std::boolalpha
            << std::is_const<
                   typename std::remove_reference<decltype(param)>::type>::value
            << std::endl;
}

int main(int argc, char const* argv[]) {
  // case1:
  if (false) {
    // reference
    {
      int x = 27;         // x is an int
      const int cx = x;   // cx is a const int
      const int& rx = x;  // rx is a reference to x as a const int
      std::cout << "int" << std::endl;
      f_reference(x);  // T is int, param's type is int&
      std::cout << "const int" << std::endl;
      f_reference(cx);  // T is const int,
                        // param's type is const int&
      std::cout << "const int&" << std::endl;
      f_reference(rx);  // T is const int,
                        // param's type is const int&
      std::cout << "int" << std::endl;
      f_const_reference(x);  // T is int, param's type is int&
      std::cout << "const int" << std::endl;
      f_const_reference(cx);  // T is int,
                              // param's type is const int&
      std::cout << "const int&" << std::endl;
      f_const_reference(rx);  // T is  int,
                              // param's type is const int&
    }
    // Pointer
    {
      int x = 27;          // as before
      const int* px = &x;  // px is a ptr to x as a const int

      std::cout << "int *" << std::endl;
      f_pointer(&x);  // T is int, param's type is int*
      std::cout << "const int*" << std::endl;
      f_pointer(px);  // T is const int,
      // param's type is const int*
    }
  }

  // case2:
  if (true) {
    int x = 27;
    const int cx = x;
    int& lrx = x;
    const int& clrx = x;
    int&& rrx = 12;
    const int&& crrx = 12;

    std::cout << "int x = 27;" << std::endl;
    std::cout << "pre : " << x << std::endl;
    f_universal(x);
    std::cout << "post : " << x << std::endl;

    std::cout << "const int cx = x;" << std::endl;
    std::cout << "pre : " << cx << std::endl;
    f_universal(cx);
    std::cout << "post : " << cx << std::endl;

    std::cout << "int& lrx = x;" << std::endl;
    std::cout << "pre : " << lrx << std::endl;
    f_universal(lrx);
    std::cout << "post : " << lrx << std::endl;

    std::cout << "const int& clrx = x;" << std::endl;
    std::cout << "pre : " << clrx << std::endl;
    f_universal(clrx);
    std::cout << "post : " << clrx << std::endl;

    std::cout << "int&& rrx = 12;" << std::endl;
    std::cout << "pre : " << rrx << std::endl;
    f_universal(rrx);
    std::cout << "post : " << rrx << std::endl;

    std::cout << "const int&& crrx = 12;" << std::endl;
    std::cout << "pre : " << crrx << std::endl;
    f_universal(crrx);
    std::cout << "post : " << crrx << std::endl;
  }
  return 0;
}
