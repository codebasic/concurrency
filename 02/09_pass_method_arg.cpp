#include <iostream>
#include <thread>

class Work
{
public:
  void do_some_work()
  {
    std::cout << "Worked" << std::endl;
  }
};

int main()
{
  Work my_work;
  std::thread t(&Work::do_some_work, &my_work);
  t.join();
}
