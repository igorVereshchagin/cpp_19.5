#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::ifstream words;
  std::string user_word;
  int matches = 0;
  words.open(".\\..\\words.txt");
  std::cout << "Input a word: ";
  std::cin >> user_word;
  while (!words.eof())
  {
    std::string file_word;
    words >> file_word;
    if (file_word == user_word)
      matches++;
  }
  words.close();
  std::cout << matches << " matches!" << std::endl;
  return 0;
}
