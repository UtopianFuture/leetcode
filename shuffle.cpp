#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<int> num;
  vector<int> tmp;
  int size;

public:
  Solution(vector<int> &nums) {
    this->size = (int)nums.size();
    this->num = nums;
    this->tmp.resize(size); // this is important
    for (int i = 0; i < size; i++) {
      this->tmp[i] = nums[i];
    }
  }

  vector<int> reset() { return tmp; }

  vector<int> shuffle() {
    int r;
    for (int i = 0; i < size; i++) {
      r = rand() % (size - i) + i;
      swap(num[i], num[r]);
    }
    return num;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  int tmp;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }
  Solution *obj = new Solution(nums);
  vector<int> param_1 = obj->reset();
  for (int i = 0; i < n; i++) {
    cout << param_1[i] << " ";
  }
  cout << "\n";
  vector<int> param_2 = obj->shuffle();
  for (int i = 0; i < n; i++) {
    cout << param_2[i] << " ";
  }
  cout << "\n";
  return 0;
}
