#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

struct Download
{
  std::string const& url;
  Download(std::string const& url_): url(url_){}

  void operator()()
  {
      std::cout << "Downloaded " << url << std::endl;
  }
};

int main()
{
  Download downloads[2] = {Download("file1"), Download("file2")};
  for(auto task : downloads)
  {
      std::thread t(task);
      t.detach();
  }
  std::this_thread::sleep_for(2s);
}
