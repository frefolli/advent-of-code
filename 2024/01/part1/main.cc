#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <fstream>
#include <istream>
#include <iostream>
#include <vector>
#include <cassert>

inline bool append_int(std::vector<int>& list, std::istream& in) {
  static int x;
  if (!(in >> x))
    return false;
  list.push_back(x);
  return true;
}

int main() {
  std::vector<int> left;
  std::vector<int> right;
  std::ifstream file ("input.txt");
  while (append_int(left, file)) {
    append_int(right, file);
  }
  file.close();
  assert(left.size() == right.size());
  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());

  uint64_t length = left.size();
  int64_t sum = 0;
  for (uint64_t i = 0; i < length; ++i) {
    sum += abs(left[i] - right[i]);
  }
  std::cout << "Sum is " << sum << std::endl;
}
