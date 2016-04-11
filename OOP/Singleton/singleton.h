#ifndef SINGLETON_H
#define SINGLETON_H

#include <cstddef>
#include <iostream>
class Singleton {
  Singleton ( );
public:
  static Singleton& getInstance ( );
  void method ( );
};

#endif // SINGLETON_H
