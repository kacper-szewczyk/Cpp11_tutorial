#include <iostream>
#include <exception>

using namespace std;

class Base {
public:
  Base();
};

class Derived {
public:
  Derived();
};

int main () {
  Base * base = new Base;
  Derived * derivedFromBase = reinterpret_cast<Derived*> (base);
  return 0;
}

Base::Base() {
  std::cout << "Base constructor" << std::endl;
}

Derived::Derived() {
  std::cout << "Derived constructor" << std::endl;
}
