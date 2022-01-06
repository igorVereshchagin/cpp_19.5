#include <iostream>
#include <fstream>
#include <string>


int main()
{
  std::ifstream payments;
  payments.open("..\\payments.txt");
  if (!payments.is_open())
  {
    std::cout << "Can't open payments.txt" << std::endl;
    return -1;
  }
  int total = 0;
  int max = 0;
  std::string max_name;
  while(!payments.eof())
  {
    int amount;
    std::string dummy_date;
    std::string first_name;
    std::string last_name;
    payments >> first_name >> last_name >> amount >> dummy_date;
    if (amount > max)
    {
      max_name = first_name;
      max_name.append(" ");
      max_name.append(last_name);
      max = amount;
    }
    total += amount;
    std::cout << first_name << " " << last_name << " " << amount << " " << total << std::endl;
//    (void)dummy_date;
  }
  payments.close();
  std::cout << "Total payments: " << total << std::endl << "Max amount to: " << max_name << std::endl;
  return 0;
}
