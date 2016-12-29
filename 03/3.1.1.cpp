#include <iostream>
#include <list>
#include <mutex>
#include <algorithm>

class Data
{
  std::mutex mutex;
  std::list<int> numbers;

public:
  Data(){}

  void add_to_list(int new_value)
  {
    std::lock_guard<std::mutex> guard(mutex);
    numbers.push_back(new_value);
  }

  bool list_contains(int value_to_find)
  {
    std::lock_guard<std::mutex> guard(mutex);
    return std::find(numbers.begin(), numbers.end(), value_to_find) != numbers.end();
  }
};

int main()
{
  Data data;

  std::cout << "contains(36): " << data.list_contains(36) << std::endl;
  data.add_to_list(36);
  std::cout << "contains(36): " << data.list_contains(36) << std::endl;
}
