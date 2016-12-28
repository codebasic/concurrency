#include <iostream>
#include <thread>
#include <chrono>
#include <cassert>

using namespace std::chrono_literals;

struct func
{
  int& i;
  func(int& i_): i(i_){}

  void operator()()
  {
    for(int j=0; j<10000; ++j){
      i += j;
    }
  }
};

void dont_wait_for_result(){
  int state = 0;
  func work(state);
  std::thread t(work);
  t.detach();
  std::cout << "problem: " << state << std::endl;
}

int main()
{
  int answer {0};
  for(int i=0; i<10000; ++i){
    answer += i;
  }
  std::cout << "Correct: " << answer << std::endl;

  dont_wait_for_result();
  // std::this_thread::sleep_for(3s);
}
