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

//  Case 3: ParamType is Neither a Pointer nor a Reference
template <typename T>
void f_NON(T param) {
  std::cout << "T param" << std::endl;
  std::cout << "f_NON T Type -> " << typeid(T).name() << " pointer -> "
            << std::boolalpha << std::is_pointer<T>::value
            << " lvalue reference -> " << std::boolalpha
            << std::is_lvalue_reference<T>::value << " rvalue reference -> "
            << std::boolalpha << std::is_rvalue_reference<T>::value
            << " const -> " << std::boolalpha
            << std::is_const<typename std::remove_reference<T>::type>::value
            << std::endl;

  std::cout << "f_NON param Type -> " << typeid(decltype(param)).name()
            << " pointer -> " << std::boolalpha
            << std::is_pointer<decltype(param)>::value
            << " lvalue reference -> " << std::boolalpha
            << std::is_lvalue_reference<decltype(param)>::value
            << " rvalue reference -> " << std::boolalpha
            << std::is_rvalue_reference<decltype(param)>::value << " const -> "
            << std::boolalpha
            << std::is_const<
                   typename std::remove_reference<decltype(param)>::type>::value
            << std::endl;
}

// Array argument
template <typename T>
void f_1(T param) {
  std::cout << "T param" << std::endl;
  std::cout << "f_arr_1 T Type -> " << typeid(T).name() << " pointer -> "
            << std::boolalpha << std::is_pointer<T>::value << " reference -> "
            << std::boolalpha << std::is_reference<T>::value << " array -> "
            << std::boolalpha << std::is_array<T>::value << std::endl;
  std::cout << "f_arr_1 param Type -> " << typeid(decltype(param)).name()
            << " pointer -> " << std::boolalpha
            << std::is_pointer<decltype(param)>::value << " reference -> "
            << std::boolalpha << std::is_reference<decltype(param)>::value
            << " array -> " << std::boolalpha
            << std::is_array<
                   typename std::remove_reference<decltype(param)>::type>::value
            << std::endl;
}

template <typename T>
void f_2(T& param) {
  std::cout << "T& param" << std::endl;
  std::cout << "f_arr_2 T Type -> " << typeid(T).name() << " pointer -> "
            << std::boolalpha << std::is_pointer<T>::value << " reference -> "
            << std::boolalpha << std::is_reference<T>::value << " array -> "
            << std::boolalpha << std::is_array<T>::value << std::endl;
  std::cout << "f_arr_2 param Type -> " << typeid(decltype(param)).name()
            << " pointer -> "  //
            << std::boolalpha << std::is_pointer<decltype(param)>::value
            << " reference -> "  //
            << std::boolalpha << std::is_reference<decltype(param)>::value
            << " array -> "  //
            << std::boolalpha
            << std::is_array<
                   typename std::remove_reference<decltype(param)>::type>::value
            << std::endl;
}

int main(int argc, char const* argv[]) {
  // case1:
  if (true) {
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
    f_universal(x);

    std::cout << "const int cx = x;" << std::endl;
    f_universal(cx);

    std::cout << "int& lrx = x;" << std::endl;
    f_universal(lrx);

    std::cout << "const int& clrx = x;" << std::endl;
    f_universal(clrx);

    std::cout << "int&& rrx = 12;" << std::endl;
    f_universal(rrx);

    std::cout << "const int&& crrx = 12;" << std::endl;
    f_universal(crrx);
    std::cout << "12" << std::endl;
    f_universal(12);
  }
  // case:3
  if (true) {
    int x = 27;
    const int cx = x;
    int& lrx = x;
    const int& clrx = x;
    int&& rrx = 12;
    const int&& crrx = 12;
    int* ptr = &x;
    int* const ptrc = &x;
    const int* cptr = &x;
    const int* const cptrc = &x;
    *ptr = 13;
    ptr = &x;
    *ptrc = 13;
    // ptrc = &x;
    // *cptr = 13 ;
    cptr = &x;
    // *cptrc = 13 ;
    // cptrc = &x;
    std::cout << "int x = 27;" << std::endl;
    f_NON(x);

    std::cout << "const int cx = x;" << std::endl;
    f_NON(cx);

    std::cout << "int& lrx = x;" << std::endl;
    f_NON(lrx);

    std::cout << "const int& clrx = x;" << std::endl;
    f_NON(clrx);

    std::cout << "int&& rrx = 12;" << std::endl;
    f_NON(rrx);

    std::cout << "const int&& crrx = 12;" << std::endl;
    f_NON(crrx);
    std::cout << "12" << std::endl;
    f_NON(12);
    std::cout << "int* ptr" << std::endl;
    f_NON(ptr);
    std::cout << "int* const ptrc" << std::endl;
    f_NON(ptrc);
    std::cout << "const int* cptr" << std::endl;
    f_NON(cptr);
    std::cout << "const int* const cptrc" << std::endl;
    f_NON(cptrc);
  }
  // Array Arguments
  if (true) {
    int arr[12];
    f_1(arr);
    f_2(arr);
  }
  // Funtion Arguments Arguments
  if (true) {
    void f1(int param);
    f_1(f1);
    f_2(f1);
  }
  return 0;
}
void f1(int param){}
