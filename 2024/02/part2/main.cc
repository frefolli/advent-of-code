#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>

inline std::vector<int> collect_report(std::string line) {
  std::vector<int> res = {};
  std::istringstream in (line);
  int x;
  while(in >> x) {
    res.push_back(x);
  }
  return res;
}

template<typename Fn>
bool check_safeness(std::vector<int> report, Fn is_pair_safe, bool erase_left) {
  uint64_t index = 0;
  bool can_erase_a_level = true;
  while (index < report.size() - 1) {
    if (!is_pair_safe(report[index], report[index + 1])) {
      if (!can_erase_a_level) {
        return false;
      }
      can_erase_a_level = false;
      if (erase_left) {
        report.erase(report.begin() + index + 1);
      } else {
        report.erase(report.begin() + index);
        if (index > 0) {
          index -= 1;
        }
      }
    } else {
      index += 1;
    }
  }
  return true;
}

bool pair_is_safe_by_increment(int x, int y) {
  return x < y && y - x <= 3;
}

bool pair_is_safe_by_decrement(int x, int y) {
  return x > y && x - y <= 3;
}

int main() {
  std::ifstream file ("input.txt");
  std::string line;
  int sum = 0;
  while(std::getline(file, line)) {
    std::vector<int> report = collect_report(line);
    if (check_safeness(report, pair_is_safe_by_increment, true)
     || check_safeness(report, pair_is_safe_by_increment, false)
     || check_safeness(report, pair_is_safe_by_decrement, true)
     || check_safeness(report, pair_is_safe_by_decrement, false))
      sum += 1;
  }
  std::cout << sum << std::endl;
  file.close();
}
