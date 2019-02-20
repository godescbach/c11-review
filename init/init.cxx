#include <iostream>
#include <string>
#include <vector>
#include <map>

int main(int argc, char* argv[])
{
  // Prefer uniform initialization over other initialization notations
  std::string oldway("old way");
  std::string newway {"new way"};

  int m=int();
  int n={0};
  int x=5;
  int y={5};

  std::string s="goodbye old way";
  std::string t { "hello new way" };

  struct S {
    int x;

    S(): x(0) {}
  };

  struct T {
    int y;

    T(): y{0} {}
  };

  // brace initializers still work for arrays
  int arr[4] = { 0, 1, 2, 3 };

  std::vector<int> vec = { 0, 1, 2, 3 };
  std::vector<std::string> strings = { "first", "second", "third"};

  // container initialization which makes sense
  std::map<std::string, std::string> singers = { 
    {"Lady Gaga", "+1 (212) 555-7890"},
    {"Beyonce Knowles", "+1 (212) 555-0987"}
  };

  // now in-class initialization of data members
  class C {
    int a {0};  //C++11 only
    int b = 5;  //C++11 only
  public:
    C();
  };


  return 0;
}
