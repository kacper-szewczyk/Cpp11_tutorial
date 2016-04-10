#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

struct Base {
  Base() {
    std::cout << "Base constructor\n";
  }
  ~Base() {
    std::cout << "Base destructor\n";
  }
};

struct Derived
        : public Base {
  Derived() {
    std::cout << "Derived constructor\n";
  }
  ~Derived() {
    std::cout << "Derived destructor\n";
  }
};

int main() {
  std::shared_ptr< Base > pointer = std::make_shared< Derived >();

  std::cout << "Created a shared_ptr Derived to Base\n"
            << "  pointer.get() = " << pointer.get()
            << ", pointer.use_count() = " << pointer.use_count() << '\n';
  std::vector < std::shared_ptr< Base > > pointers;
  for (int i = 0; i < 3; ++i) {
    pointers.push_back(pointer);
  }
  std::cout << "Shared ownership \n"
            << "  pointer.get() = " << pointer.get()
            << ", pointer.use_count() = " << pointer.use_count() << '\n';
  pointer.reset();
  for (int i = 0; i < 3; ++i){
    std::cout << "pointers[" << i << "].use_count() = "
              << pointers[i].use_count() << '\n';
    pointers[i].reset();
  };
  std::cout << "All pointers reseted, the last one deleted Derived\n";
}
