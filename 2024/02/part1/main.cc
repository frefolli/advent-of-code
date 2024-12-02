#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

bool all_ascent(std::istringstream& in, int x) {
  int y;
  while (in >> y) {
    if (x >= y) {
      return false;
    }
    if (y - x > 3)
      return false;
    x = y;
  }
  return true;
}

bool all_descent(std::istringstream& in, int x) {
  int y;
  while (in >> y) {
    if (x <= y) {
      return false;
    }
    if (x - y > 3)
      return false;
    x = y;
  }
  return true;
}

int main() {
  std::ifstream file ("input.txt");
  std::string line;
  int sum = 0;
  while(std::getline(file, line)) {
    std::istringstream in (line);
    int x, y;
    in >> x;
    in >> y;
    if (x > y) {
      if (x - y <= 3 && all_descent(in, y))
        sum += 1;
    } else if (x < y) {
      if (y - x <= 3 && all_ascent(in, y))
        sum += 1;
    }
  }
  std::cout << sum << std::endl;
  file.close();
}
