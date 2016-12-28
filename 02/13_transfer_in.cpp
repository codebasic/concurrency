#include <thread>

void foo(std::thread t){
  if(t.joinable()){
    t.join();
  }
}
void goo(){}

int main()
{
  foo(std::thread(goo));

  std::thread t(goo);
  foo(std::move(t));
}
