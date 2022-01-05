#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::string filename;
  std::cout << "Input path\\to\\file: " << std::endl;
  std::getline(std::cin, filename);
  std::ifstream user_file;
  user_file.open(filename, std::ios::binary);
  if (!user_file.is_open())
  {
    std::cout << "Can not open file: " << filename << std::endl;
    return -1;
  }
  char buf [20];
  while  (!user_file.eof())
  {
    user_file.read(buf, sizeof(buf) - 1);
    buf[user_file.gcount()] = 0;
    std::cout << buf;
  }
  user_file.close();
  return 0;
}
