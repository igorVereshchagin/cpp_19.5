#include <iostream>
#include <fstream>
#include <string>

int main()
{
  int players_score = 0;
  int tv_score = 0;
  int roulette = 0;
  int used_sectors_mask = 0;
  do
  {
    int offset;
    std::cout << "Input offset: ";
    std::cin >> offset;
    roulette = (roulette + offset) % 13;
    while (0 != (used_sectors_mask & (1 << roulette)))
      roulette = (roulette + 1) % 13;
    used_sectors_mask |= 1 << roulette;
    std::string sector = std::to_string(roulette + 1);
    std::cout << "Sector " << sector << " dropped" << std::endl;
    std::ifstream question_file;
    std::string filename = "..\\quiz\\";
    filename.append(sector);
    filename.append(".qsn");
    question_file.open(filename);
    if (!question_file.is_open())
    {
      std::cout << "MCs failure. There should be file " << filename << std::endl;
      return -1;
    }
    std::string question;
    std::getline(question_file, question);
    question_file.close();
    std::cout << question << std::endl;
    std::cout << "Input answer: " << std::endl;
    std::string player_answer;
    std::cin >> player_answer;
    std::ifstream answer_file;
    filename = "..\\quiz\\";
    filename.append(sector);
    filename.append(".ans");
    answer_file.open(filename);
    if (!answer_file.is_open())
    {
      std::cout << "MCs failure. There should be file " << filename << std::endl;
      return -1;
    }
    std::string tv_answer;
    answer_file >> tv_answer;
    answer_file.close();
    if (tv_answer == player_answer)
    {
      players_score++;
      std::cout << "Right!" << std::endl;
    }
    else
    {
      tv_score++;
      std::cout << "Wrong!" << std::endl;
    }
    std::cout << "Current score:   " << "TV viewers: " << tv_score << "    Players: " << players_score << std::endl;
  }while (players_score < 6 && tv_score < 6);
  if (players_score == 6)
    std::cout << "Players ";
  else
    std::cout << "TV viewers ";
  std::cout << "WON!" << std::endl;
  return 0;
}
