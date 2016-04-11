#include <iostream>
#include <array>
#include <assert.h>

#define VECTOR_LENGTH 10

void simplestLambdaUsage ();

void variableCaptureLambdaUsage ();

void valueCaptureLambdaUsage ();

void lambdaWithRetValue ();

void lambdaWithCopyCapture ();

int main (int argc, char *argv[]) {
  simplestLambdaUsage ();
  std::cout << std::endl << std::endl;

  variableCaptureLambdaUsage ();
  std::cout << std::endl << std::endl;

  valueCaptureLambdaUsage ();
  std::cout << std::endl << std::endl;

  lambdaWithRetValue ();
  std::cout << std::endl << std::endl;

  lambdaWithCopyCapture ();
  std::cout << std::endl << std::endl;

  return 0;
}

void simplestLambdaUsage () {
  std::cout << "simplestLambdaUsage ()" << std::endl;
  auto simpleLambda = [] {
      std::cout << "Hello World!\n";
  };
  simpleLambda();
}

void variableCaptureLambdaUsage () {
  std::cout << "variableCaptureLambdaUsage ()" << std::endl;
  std::array<int, VECTOR_LENGTH> numbers;
  int index = 0;
  auto variableCaptureLambda =
      [&](int *value){
      *value = index;
      index ++;
  };
  for ( auto number = numbers.begin();
             number != numbers.end();
             number ++){
    variableCaptureLambda ( number );
  }

  for (const auto& number : numbers) {
    std::cout << number << " ";
  }
  std::cout << std::endl;
}

void valueCaptureLambdaUsage () {
  std::cout << "valueCaptureLambdaUsage ()" << std::endl;
  int passedByValue = 0;
  int passedByReference = 0;
  [&, passedByValue] (int value) mutable {
    passedByReference =
        ++passedByValue + value;
    std::cout << "Inside lambda ";
    std::cout << passedByValue << std::endl
              << passedByReference << std::endl;
  }(4);
  assert ( passedByValue == 0 );
  assert ( passedByReference == 5 );
  std::cout << "Outside lambda only second variable stays changed \n";
  std::cout << passedByValue << std::endl
            << passedByReference << std::endl;
}


void lambdaWithRetValue () {
  std::cout << "lambdaWithRetValue ()" << std::endl;
  auto f = []()->char * {
      return "Hello";
  };
  std::cout << f( ) << std::endl;
}


void lambdaWithCopyCapture () {
  std::cout << "lambdaWithCopyCapture ()" << std::endl;
  int passedByValue = 0;
  int passedByReference = 0;
  [=, passedByValue] (int value) mutable {
    passedByReference =
          ++passedByValue + value;
    std::cout << "Inside lambda  ";
    std::cout << passedByValue << std::endl
              << passedByReference << std::endl;

  }(4);
  assert ( passedByValue == 0 );
  assert ( passedByReference == 0 );
  std::cout << "Outside lambda everything is back to normal \n";
  std::cout << passedByValue << std::endl
            << passedByReference << std::endl;
}
