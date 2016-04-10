#include <iostream>

class Base {};

class Derived {
public:
  Derived (const Base& x);
  Derived& operator = (const Base& x);
  operator Base();
};

Derived::Derived (const Base& x) {
  std::cout << "Constructor called" << std::endl;
}

Derived& Derived::operator = (const Base& x) {
  std::cout << "Assignment called" << std::endl;
  return *this;
}

Derived::operator Base() {
  std::cout << "type-cast operator called" << std::endl;
  return Base();
}

int main ()
{
  Base base;
  Derived derived = base;
  derived = base;
  base = derived;
  return 0;
}
