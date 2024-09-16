#include <iostream>
int main(int argc, char const *argv[]) {
  int x = 27;
  const int cx = x;
  int &lrx = x;
  const int &clrx = x;
  int &&rrx = 12;
  const int &&crrx = 12;
  int *ptr = &x;
  int *const ptrc = &x;
  const int *cptr = &x;
  const int *const cptrc = &x;

  {
    { auto i = x; }
    { auto i = 12; }
    { auto i = std::move(x); }
    { auto i = cx; }
    { auto i = lrx; }
    { auto i = clrx; }
    { auto i = rrx; }
    { auto i = crrx; }
    { auto i = ptr; }
    { auto i = ptrc; }
    { auto i = cptr; }
    { auto i = cptrc; }
  }
  {
    { auto &i = x; }
    //{ auto &i = 12; }
    //{ auto &i = std::move(x); }
    { auto &i = cx; }
    { auto &i = lrx; }
    { auto &i = clrx; }
    { auto &i = rrx; }
    { auto &i = crrx; }
    { auto &i = ptr; }
    { auto &i = ptrc; }
    { auto &i = cptr; }
    { auto &i = cptrc; }
  }

  {
    { auto &&i = x; }
    { auto &&i = 12; }
    { auto &&i = std::move(x); }
    { auto &&i = cx; }
    { auto &&i = lrx; }
    { auto &&i = clrx; }
    { auto &&i = rrx; }
    { auto &&i = crrx; }
    { auto &&i = ptr; }
    { auto &&i = ptrc; }
    { auto &&i = cptr; }
    { auto &&i = cptrc; }
  }

  {
    const char name[] = "R. N. Briggs";
    auto arr1 = name;
    auto &arr2 = name;
    const char(&arr3)[13] = name;
    void someFunc(int, double);
    auto func1 = someFunc;
    auto &func2 = someFunc;
  }
  {
    // OK INT
    int x1 = 27;
    int x2(27);
    int x3 = {27};
    int x4{27};
    // NOT OK INT
    auto x1 = 27;
    auto x2(27);
    auto x3 = {27};
    auto x4{27};
    // auto x5 = {27, 27.12};
    // auto x6{27, 25};
  }
  return 1;
}
