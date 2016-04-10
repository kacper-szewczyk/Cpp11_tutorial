#include <iostream>
#include <tr1/memory>
#include <auto_ptr.h>
#include <exception>
using namespace std;

class Test {
public:
  Test (int a = 0 )
      : field(a) {
  }
  ~Test ( ) {
    cout << "Still running destructor" << endl;
  }
  int field;
};

void functionToCrush( ) {
  int a = 0;
  int b = 5;
  int c = 0;
  if( a == 0 ) {
    throw "Invalid divisor";
  }
  c = b/a;
  return;
}

int main( )
{
  try {
    std::auto_ptr<Test> p( new Test(5) );
    functionToCrush( );
    cout << p -> field << endl;
  }
  catch (...) {
    cout << "Something went wrong" << endl;
  }
  return 0;

}
