#include <iostream>
using namespace std;

void print (int * value){
  cout << *value << '\n';
}

int main () {
  int value = 123;
  const int * pointerToValue = &value;
  print ( const_cast<int *> (pointerToValue) );
  return 0;
}
