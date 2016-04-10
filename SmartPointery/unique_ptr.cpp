#include <iostream>
#include <memory>
#include <exception>

struct Base {
  Base() {
    std::cout << "Base constructor\n";
  }
  ~Base() {
    std::cout << "Base destructor\n";
  }
  void foo() {
    std::cout << "Method foo()\n";
  }
};

void function ( const Base & ) {
  std::cout << "function ( const Base & )\n";
}

int main() {
  std::unique_ptr< Base > pointer(new Base);
  if ( pointer ) {
    pointer->foo();
  }
  {
    std::unique_ptr< Base > pointer2 (
                std::move ( pointer ) );
    function ( *pointer2 );
    pointer = std::move ( pointer2 );
    std::cout << "Destroing pointer2\n";
  }
  if ( pointer ) {
    pointer->foo();
  }
  return 0;
}
