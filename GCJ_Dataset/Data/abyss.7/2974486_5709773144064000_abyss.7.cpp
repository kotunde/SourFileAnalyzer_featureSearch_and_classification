#include <iostream>
#include <limits>

int main() {
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": ";
    std::cout.precision(7);

    double C, F, X, speed = 2.;
    std::cin >> C >> F >> X;

    double min_time = X / speed, total_farm_time = 0.;
    while(true) {
      double farm_time = C / speed;
      speed += F;
      double win_time = X / speed;

      const auto epsilon = std::numeric_limits<double>::epsilon();
      if ( win_time + farm_time > min_time ||
          (win_time + farm_time - min_time < epsilon &&
           win_time + farm_time - min_time > -epsilon)) break;
      min_time = win_time;
      total_farm_time += farm_time;
    }
    std::cout << std::fixed << min_time + total_farm_time;

    std::cout << std::endl;
  }
}
