#include <iostream>
#include <thread>
#include <chrono>
#include <random>

using namespace std::chrono_literals;

void random_sleep(int low, int high)
{
  std::mt19937_64 eng {std::random_device{}()};
  std::uniform_int_distribution<> dist{low, high};
  std::this_thread::sleep_for(std::chrono::seconds{dist(eng)});
}

void download(std::string const& url)
{
  random_sleep(1,10);
  std::cout << "Downloaded " << url << std::endl;
}

int main()
{
  std::string urls[2] {"file1", "file2"};
  for(auto url : urls)
  {
      std::thread t(download, url);
      t.detach();
  }
  std::this_thread::sleep_for(20s);
}
