//#include <iostream>

struct A
{
  A()=default; // C++11

  virtual ~A()=default; // C++11
};

int main(int argc, char* argv[])
{
  struct A a;
  return 0;
}
