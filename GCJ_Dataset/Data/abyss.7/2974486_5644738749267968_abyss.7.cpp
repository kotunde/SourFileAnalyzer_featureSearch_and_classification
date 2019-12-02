#include <iostream>
#include <map>

enum Player { Naomi, Ken };

int main() {
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": ";

    int N;
    std::cin >> N;

    std::map<int, Player> blocks;
    for (int j = 0; j < N; ++j) {
      std::string kg;
      std::cin >> kg;
      kg += std::string(8 - kg.size(), '0');
      kg = kg.substr(2);
      blocks.emplace(std::stoi(kg), Naomi);
    }
    for (int j = 0; j < N; ++j) {
      std::string kg;
      std::cin >> kg;
      kg += std::string(8 - kg.size(), '0');
      kg = kg.substr(2);
      blocks.emplace(std::stoi(kg), Ken);
    }

    {
      int opp = 0, trans = 0;
      for (const auto& it: blocks) {
        if (it.second == Ken) ++opp;
        else if (opp > 0) { ++trans; --opp; }
      }
      std::cout << trans << " ";
    }

    {
      int opp = 0, trans = 0;
      for (const auto& it: blocks) {
        if (it.second == Naomi) ++opp;
        else if (opp > 0) { ++trans; --opp; }
      }
      std::cout << (N - trans);
    }

    std::cout << std::endl;
  }
}
