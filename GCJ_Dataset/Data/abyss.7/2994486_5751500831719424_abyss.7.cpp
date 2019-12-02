#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

const std::string impossible = "Fegla Won";

int main() {
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": ";

    int N;
    std::cin >> N;

    std::string result1 = std::string();
    std::map<int, std::list<int>> strings;
    int output = 0;
    for (int j = 0; j < N; ++j) {
      std::string str;
      std::cin >> str;

      if (output == -1) continue;

      char prev = str[0];
      std::string result2;
      result2 += prev;
      int char_count = 0;
      strings[char_count].emplace_back(1);
      for (size_t k = 1; k < str.size(); k++) {
        if (str[k] == prev) {
          (*strings[char_count].rbegin())++;
          continue;
        }
        char_count++;
        prev = str[k];
        result2 += prev;
        strings[char_count].emplace_back(1);
      }

      if (result1.empty()) result1 = result2;
      else if (result1 != result2) output = -1;
    }

    if (output == -1) std::cout << impossible;
    else {
      for (const auto& str: strings) {
        int max = 10001;
        for (const auto& ch: str.second) {
          int res = 0;
          for (const auto& ch2: str.second) {
            res += std::abs(ch2 - ch);
          }
          max = std::min(res, max);
        }
        output += max;
      }
      std::cout << output;
    }

    std::cout << std::endl;
  }
}
