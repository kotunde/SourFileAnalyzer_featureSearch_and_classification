#include <iostream>
#include <set>

const char* bad_magician = "Bad magician!";
const char* cheated = "Volunteer cheated!";

int main() {
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i) {
    int answer[2];
    std::set<int> state[2][4];
    for (int k = 0; k < 2; ++k) {
      std::cin >> answer[k];
      for (int j = 0; j < 16; ++j) {
        int card;
        std::cin >> card;
        state[k][j/4].insert(card);
      }
    }

    std::cout << "Case #" << i << ": ";

    int count = 0;
    int card = 0;
    const auto& row1 = state[0][answer[0] - 1];
    const auto& row2 = state[1][answer[1] - 1];
    for (auto it = row1.begin(); it != row1.end(); ++it) {
      if (row2.find(*it) != row2.end()) {
        ++count;
        card = *it;
      }
    }

    if (count == 0) std::cout << cheated;
    else if(count == 1) std::cout << card;
    else std::cout << bad_magician;

    std::cout << std::endl;
  }
}
