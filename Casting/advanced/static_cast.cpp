#include <iostream>
#include <exception>

using namespace std;

class Base {
public:
  Base();
};

class Derived:
        public Base {
public:
  Derived();
};

int main () {
  Base * base = new Base;
  Derived * derived = static_cast<Derived*> (base);
  return 0;
}

Base::Base() {
  std::cout << "Base constructor" << std::endl;
}

Derived::Derived() {
  std::cout << "Derived constructor" << std::endl;
}
