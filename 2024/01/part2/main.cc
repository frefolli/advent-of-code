#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <istream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>

inline bool append_int(std::vector<int>& list, std::istream& in) {
  static int x;
  if (!(in >> x))
    return false;
  list.push_back(x);
  return true;
}

inline bool record_int(std::unordered_map<int, uint64_t>& map, std::istream& in) {
  static int x;
  if (!(in >> x))
    return false;
  map[x]++;
  return true;
}


int main() {
  std::vector<int> left;
  std::unordered_map<int, uint64_t> right;
  std::ifstream file ("input.txt");
  while (append_int(left, file)) {
    record_int(right, file);
  }
  file.close();

  int64_t sum = 0;
  for (const int& x : left) {
    sum += right[x] * x;
  }
  std::cout << "Sum is " << sum << std::endl;
}
