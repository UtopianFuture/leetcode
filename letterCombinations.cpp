#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<string> res;
  string digits;

public:
  void backtrace(unordered_map<int, string> map, int start, string tmp,
                 string digits) {
    if ((int)tmp.size() == (int)digits.size()) {
      res.push_back(tmp);
      return;
    }

    for (int i = 0; i < (int)map[digits[start] - '0'].size(); i++) {
      tmp.push_back(map[digits[start] - '0'][i]);
      backtrace(map, start + 1, tmp, digits);
      tmp.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    if ((int)digits.size() == 0) {
      return res;
    }
    unordered_map<int, string> map;
    map[2] = "abc";
    map[3] = "def";
    map[4] = "ghi";
    map[5] = "jkl";
    map[6] = "mno";
    map[7] = "pqrs";
    map[8] = "tuv";
    map[9] = "wxyz";
    string tmp;
    backtrace(map, 0, tmp, digits);
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  vector<string> res = so->letterCombinations(s);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
