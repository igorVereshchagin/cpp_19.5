#include <iostream>
#include <string>
#include <fstream>

int main()
{
  std::string filename;
  std::cout << "Input path\\to\\file: " << std::endl;
  std::getline(std::cin, filename);
  std::ifstream png_file;
  png_file.open(filename, std::ios::binary);
  if (!png_file.is_open())
  {
    std::cout << "Can't open file: " << filename << std::endl;
    return -1;
  }
  char buf[4];
  png_file.read(buf, 4);
  std::cout << "File " << filename << " is ";
  if (png_file.gcount() != 4 || buf[0] != -119 || buf[1] != 'P' || buf[2] != 'N' || buf[3] != 'G')
    std::cout << "NOT ";
  std::cout << "a PNG file!" << std::endl;
  png_file.close();
  return 0;
}
