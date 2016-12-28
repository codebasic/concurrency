#include <iostream>
#include <thread>

class thread_guard
{
  std::thread& t;
public:
  thread_guard(std::thread& t_): t(t_){}
  ~thread_guard()
  {
    if(t.joinable())
    {
      t.join();
    }
  }
  // 복사 방지
  thread_guard(thread_guard const&)=delete;
  thread_guard& operator=(thread_guard const&)=delete;
};

struct func
{
  int& i;
  func(int& i_): i(i_){}

  void operator()()
  {
    for(unsigned j=0; j<1000000; ++j){
      i += j;
    }
    std::cout << "Finished: " << i << std::endl;
  }
};

int main()
{
  int state = 0;
  func work(state);
  std::thread t(work);
  thread_guard g(t);

  std::cout << "Local: " << state << std::endl;
}
