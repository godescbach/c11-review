#include <algorithm>
#include <iostream>

int main(int argc, char* argv[])
{
  char s[] = "Hello World!";

  int uppercase = 0;

  std::for_each(s, s+sizeof(s), [&uppercase](char c) {
    if (isupper(c))
      ++uppercase;
  });
  std::cout << uppercase << " uppercase letters in: " << s << std::endl;
  return 0;
}
