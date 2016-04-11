#include "singleton.h"

Singleton::Singleton () {

}

Singleton & Singleton::getInstance () {
  static Singleton instance;
  return instance;
}

void Singleton::method ( ) {
  std::cout << "Method called\n";
}
