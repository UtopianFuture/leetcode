#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class RandomizedSet {
  vector<int> nums;
  unordered_map<int, int> index;
  int count;

public:
  RandomizedSet() { this->count = 0; }

  bool insert(int val) {
    if (index.find(val) != index.end()) {
      return false;
    } else {
      nums.push_back(val);
      index[val] = (int)nums.size() - 1;
      return true;
    }
  }

  bool remove(int val) {
    if (index.find(val) == index.end()) {
      return false;
    } else {
      int tmp_index = find(nums.begin(), nums.end(), val) - nums.begin();
      int tmp_val = nums[nums.size() - 1];
      if (tmp_index == (int)nums.size() - 1) {
        nums.erase(nums.end() - 1, nums.end());
        index.erase(val);
        return true;
      }
      swap(nums[index[val]], nums[nums.size() - 1]);
      nums.erase(nums.end() - 1, nums.end());
      index[tmp_val] = tmp_index;
      index.erase(val);
      return true;
    }
  }

  int getRandom() {
    int r = rand() % (nums.size());
    return nums[r];
  }
};

int main(int argc, char *argv[]) {
  RandomizedSet *randomizedSet = new RandomizedSet;
  randomizedSet->insert(1);
  randomizedSet->remove(2);
  randomizedSet->insert(2);
  randomizedSet->getRandom();
  randomizedSet->remove(1);
  randomizedSet->insert(2);
  randomizedSet->getRandom();
  return 0;
}
