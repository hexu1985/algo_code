#include <iostream>
#include <map>
 
int main() {
  std::map<int, float> num_map;
  num_map[4] = 4.13;
  num_map[9] = 9.24;
  num_map[1] = 1.09;
  // calls a_map.begin() and a_map.end()
  for (auto it = num_map.begin(); it != num_map.end(); ++it) {
    std::cout << it->first << ", " << it->second << '\n';
  }
}
