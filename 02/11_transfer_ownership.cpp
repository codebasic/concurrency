#include <iostream>
#include <thread>

void foo(){}
void goo(){}

int main()
{
  std::thread t1(foo);
  std::thread t2 = std::move(t1);
  t1 = std::thread(goo);
  std::thread t3;
  t3 = std::move(t2);
  // t3.join();
  // t1.join();
  t1 = std::move(t3);

  std::cout << "End" << std::endl;
}
