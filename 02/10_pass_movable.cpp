#include <iostream>
#include <thread>

struct BigData
{
  int data[100] {0};
};

void process_big_data(std::unique_ptr<BigData> p)
{
  std::fill(std::begin(p->data), std::end(p->data), 1);
}

int main()
{
  std::unique_ptr<BigData> p(new BigData);
  std::thread t(process_big_data, std::move(p));
}
