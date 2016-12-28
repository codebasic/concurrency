#include <iostream>
#include <thread>
#include <cassert>
#include <stdexcept>

using namespace std;

struct func
{
  int& i;
  func(int& i_): i(i_){}

  void operator()()
  {
    for(unsigned j=0; j<1000000; ++j){
      i += j;
    }
    cout << "Finished: " << i << endl;
  }
};

int main()
{
  int state = 0;
  func work(state);
  std::thread t(work);
  try
  {
    throw  runtime_error("things go wrong");
  }
  catch(...)
  {
    t.join();
    cout << state << endl;
    assert(state==1783293664);
  }
}
