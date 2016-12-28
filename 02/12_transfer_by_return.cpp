#include <thread>

void foo(){}
void goo(int){}

std::thread tfoo()
{
  return std::thread(foo);
}

std::thread tgoo()
{
  std::thread t(goo, 1);
  return t;
}

int main()
{
  auto t1 = tfoo();
  auto t2 = tgoo();
  t1.join();
  t2.join();
}
