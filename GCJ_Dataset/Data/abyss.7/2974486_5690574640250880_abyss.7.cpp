#include <cassert>
#include <iostream>

const char kEmpty = '.';
const char kMine = '*';
const char kClick = 'c';

template <int MaxSize>
class Field {
  public:
    Field(int R, int C, char cell = kMine)
      : r_(R), c_(C), size_(MaxSize + 2) {
      assert(r_ <= MaxSize);
      assert(c_ <= MaxSize);

      for (int i = 0; i < size_*size_; ++i)
        field_[i / size_][i % size_] = cell;

      for (int i = 0; i < r_ + 2; ++i) {
        field_[i][0] = kEmpty;
        field_[i][c_ + 1] = kEmpty;
      }

      for (int i = 0; i < c_ + 2; ++i) {
        field_[0][i] = kEmpty;
        field_[r_ + 1][i] = kEmpty;
      }
    }

    void Print() {
      field_[1][1] = kClick;
      for (int i = 0; i < r_; ++i) {
        for (int j = 0; j < c_; ++j) {
          std::cout << (*this)(i, j);
        }
        std::cout << std::endl;
      }
    }

    char& operator() (int x, int y) {
      assert(x >= 0 && x < r_);
      assert(y >= 0 && y < c_);

      return field_[x + 1][y + 1];
    }

    inline void FillRow(int r, int s, char cell = kEmpty) {
      for (int i = 0; i < s; ++i) (*this)(r, i) = cell;
    }

    inline void FillColumn(int c, int s, char cell = kEmpty) {
      for (int i = 0; i < s; ++i) (*this)(i, c) = cell;
    }

  private:
    char field_[MaxSize + 2][MaxSize + 2];
    const int r_, c_, size_;
};

int main() {
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ":" << std::endl;

    int R, C, M;
    std::cin >> R >> C >> M;

    int E = R*C - M;
    assert(E > 0);

    Field<50> field(R, C);

    // Trivial cases.
    if (E == 1) {
      field(0, 0) = kEmpty;
      field.Print();
      continue;
    }
    else if (R == 1) {
      field.FillRow(0, E);
      field.Print();
      continue;
    }
    else if (C == 1) {
      field.FillColumn(0, E);
      field.Print();
      continue;
    }
    else if (E < 4 || E == 5 || E == 7) {
      std::cout << "Impossible" << std::endl;
      continue;
    }
    else if (R == 2) {
      if (E % 2 == 1) std::cout << "Impossible" << std::endl;
      else {
        field.FillRow(0, E/2);
        field.FillRow(1, E/2);
        field.Print();
      }
      continue;
    }
    else if (C == 2) {
      if (E % 2 == 1) std::cout << "Impossible" << std::endl;
      else {
        field.FillColumn(0, E/2);
        field.FillColumn(1, E/2);
        field.Print();
      }
      continue;
    }

    // Tough cases.
    int first_pairs;

    if (R <= C) {
      if (E / 2 <= C) {
        if (E % 2 == 0) first_pairs = E / 2;
        else first_pairs = E / 2 - 1;
      }
      else first_pairs = C;

      field.FillRow(0, first_pairs);
      field.FillRow(1, first_pairs);
      E -= first_pairs * 2;
      int row = 2;

      while(E >= C) {
        if (E - C == 1) {
          field.FillRow(row, C-1);
          E -= C - 1;
        }
        else {
          field.FillRow(row, C);
          E -= C;
        }
        ++row;
      }

      field.FillRow(row, E);
    }
    else {
      if (E / 2 <= R) {
        if (E % 2 == 0) first_pairs = E / 2;
        else first_pairs = E / 2 - 1;
      }
      else first_pairs = R;

      field.FillColumn(0, first_pairs);
      field.FillColumn(1, first_pairs);
      E -= first_pairs * 2;
      int column = 2;

      while(E >= R) {
        if (E - R == 1) {
          field.FillColumn(column, R-1);
          E -= R - 1;
        }
        else {
          field.FillColumn(column, R);
          E -= R;
        }
        ++column;
      }

      field.FillColumn(column, E);
    }

    field.Print();
  }
}
