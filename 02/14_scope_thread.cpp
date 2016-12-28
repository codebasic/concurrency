#include <iostream>
#include <thread>

class scoped_thread
{
  std::thread t;
public:
  scoped_thread(std::thread t_): t(std::move(t_))
  {
    if(!t.joinable())
    {
      throw std::logic_error("No thread");
    }
  }
  ~scoped_thread()
  {
    t.join();
  }
  scoped_thread(scoped_thread const&)=delete;
  scoped_thread& operator=(scoped_thread const&)=delete;
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
  scoped_thread t(std::thread(func(state)));
  std::cout << state << std::endl;
}
