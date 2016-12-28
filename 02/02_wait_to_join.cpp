#include <iostream>
#include <thread>
#include <cassert>

using namespace std;

struct func
{
  int& i;
  func(int& i_): i(i_){}

  void operator()()
  {
    for(unsigned j=0; j<10000; ++j){
      i += j;
    }
    cout << "Finished: " << i << endl;
  }
};

void wait_for_result(){
  int state = 0;
  func work(state);
  std::thread t(work);
  t.join();
  cout << state << endl;
}

int main()
{
  int answer {0};
  for(int i=0; i<10000; ++i){
    answer += i;
  }
  std::cout << "Correct: " << answer << std::endl;

  wait_for_result();
}
