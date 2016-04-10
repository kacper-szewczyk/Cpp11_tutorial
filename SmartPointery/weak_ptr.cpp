#include <iostream>
#include <memory>


struct Base {
  Base() {
    std::cout << "Base constructor\n";
  }
  ~Base() {
    std::cout << "Base destructor\n";
  }
};

std::weak_ptr< Base > weakPointer;

void function ( ) {
  if (auto localPointer = weakPointer.lock()) { // Has to be copied into a shared_ptr before usage
    std::cout << "weakPointer points something\n";
  }
  else {
    std::cout << "weakPointer has expired\n";
  }
}

int main() {
  {
      auto pointer = std::make_shared< Base >();
      weakPointer = pointer;
      function ( );
  }
  function ( );
}
