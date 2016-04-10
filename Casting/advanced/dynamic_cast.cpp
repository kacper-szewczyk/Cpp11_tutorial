#include <iostream>
#include <exception>

using namespace std;

class Base {
  virtual void function();
};

class Derived:
        public Base {
  int a;
};

int main () {
  Base * baseToDerived = new Derived;
  Base * base = new Base;
  Derived * derived;

  derived = dynamic_cast<Derived*> (baseToDerived);
  if (derived == 0) {
    cout << "Null pointer on casting pofimorfed base.\n";
  }
  derived = dynamic_cast<Derived*> (base);
  if (derived == 0) {
    cout << "Null pointer on casting base.\n"; 
  }
  return 0;
}

void Base::function() {
  return;
}
