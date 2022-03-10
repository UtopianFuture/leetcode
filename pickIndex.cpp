#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int n;
  vector<int> nums;
  vector<int> pre;
  int sum;

public:
  Solution(vector<int> &w) {
    this->n = (int)w.size();
    this->nums = w;
    this->sum = 0;
    for (int i = 0; i < this->n; i++) {
      this->sum += w[i];
      this->pre.push_back(this->sum);
    }
  }

  int pickIndex() {
    int r = rand() % sum + 1;
    // int left = 0, right = n - 1;
    // int mid;
    // while (left < right) {
    // mid = (left + right) / 2;
    // if (pre[mid] - nums[mid] + 1 > r) {
    // right = mid - 1;
    // } else if (pre[mid] < r) {
    // left = mid + 1;
    // } else {
    // return mid;
    // }
    // }
    for(int i = 0; i < n; i++){
      if(pre[i] >= r){
        return i;
      }
    }
    return 0;
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

  Solution *s = new Solution(nums);
  int param_1 = s->pickIndex();
  cout << param_1 << " ";
  param_1 = s->pickIndex();
  cout << param_1 << " ";
  param_1 = s->pickIndex();
  cout << param_1 << " ";
  param_1 = s->pickIndex();
  cout << param_1 << " ";
  param_1 = s->pickIndex();
  cout << param_1 << " ";

  return 0;
}
