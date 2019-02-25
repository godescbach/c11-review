#include <iostream>

void func(int)
{
  std::cout << "This is func(int)." << std::endl;
}

void func(char*)
{
  std::cout << "This is func(char*)." << std::endl;
}

int main(int argc, char* argv[])
{
  std::cout << "Calling func(nullptr)." << std::endl;
  func(nullptr);
  std::cout << "Calling func(0)." << std::endl;
  func(0);
}
