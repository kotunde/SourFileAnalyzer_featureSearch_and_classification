#include <iostream>
#include <map>
#include <string>
#include <list>
#include <set>
#include <queue>

void fly_from(int city,
              std::list<int>& result,
              std::map<int, std::set<int>>& edges,
              std::map<int, std::set<int>>& used,
              std::set<int>& visited,
              std::map<int, std::string>& zips) {
  if (visited.count(city) == 0) {
    result.emplace_back(city);
    visited.insert(city);
  }

  std::map<std::string, int> nexts;
  for (const auto &edge: edges[city]) {
    if (!used[edge].count(city) && !used[city].count(edge) &&
        visited.count(edge) == 0) {
      nexts.emplace(zips[edge], edge);
      used[edge].insert(city);
      used[city].insert(edge);
    }
  }

  for (const auto& next: nexts) {
    fly_from(next.second, result, edges, used, visited, zips);
  }
}

int main() {
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": ";

    int N, M;
    std::cin >> N >> M;

    std::list<int> result;

    std::map<int, std::string> zips;
    std::map<std::string, int> strings;
    std::map<int, std::set<int>> edges;
    for (int j = 0; j < N; j++) {
      std::string zip;
      std::cin >> zip;
      if (zip.size() == 5) {
        zips[j+1] = zip;
        strings[zip] = j+1;
      }
    }

    for (int j = 0; j < M; ++j) {
      int c1, c2;
      std::cin >> c1 >> c2;
      edges[c1].emplace(c2);
      edges[c2].emplace(c1);
    }

    for (const auto& string: strings) {
      std::set<int> visited;
      std::map<int, std::set<int>> used;

      fly_from(string.second, result, edges, used, visited, zips);
      if (result.size() == zips.size()) break;
      result.clear();
    }

    for (const auto& city: result) {
      std::cout << zips[city];
    }

    std::cout << std::endl;
  }
}
