#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

void greeting(std::string const& name)
{
    std::cout << "Hello, " << name << std::endl;
}

void problem()
{
  char name[50] {"김성주"};
  std::thread t(greeting, name);
  t.detach();
}

void solution()
{
  char name[50] {"이성주"};
  std::thread t(greeting, std::string(name));
  t.detach();
}

int main()
{
  problem();
  solution();
  std::this_thread::sleep_for(2s);
}
