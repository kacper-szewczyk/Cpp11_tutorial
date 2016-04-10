#include <iostream>
#include <typeinfo>
using namespace std;

int main () {
  int value = 123;
  const int * pointerToValue = &value;
  cout << "value is: "
       << typeid(value).name()
       << endl;
  cout << "pointerToValue is: "
       << typeid(pointerToValue).name()
       << endl;

  return 0;
}
