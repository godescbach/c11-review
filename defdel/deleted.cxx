
class NoCopy
{
public:
  NoCopy() = default;
  NoCopy& operator =(const NoCopy&) = delete;

  NoCopy(const NoCopy&) = delete;
};

class B {
public:
  B& operator=(const B&) = delete;
  // B(const B&) = delete;
};

int main(int argc, char* argv[])
{
  NoCopy a;
  B b;
  return 0;
}
