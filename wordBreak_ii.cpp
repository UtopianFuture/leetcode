#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  unordered_map<string, int> map;
  vector<string> res;
  string s;

public:
  void backtrace(string tmp, int start, int end) {
    if (start == end) {
      tmp.erase(tmp.end() - 1, tmp.end());
      res.push_back(tmp);
      tmp += ' ';
      return;
    }

    for (int i = start; i < end; i++) {
      string str = s.substr(start, i - start + 1);
      if (map[str] != 1) {
        continue;
      }
      tmp = tmp + str + ' ';
      backtrace(tmp, i + 1, end);
      tmp.erase(tmp.end() - (int)str.size() - 1, tmp.end());
    }
  }

  vector<string> wordBreak(string s, vector<string> &wordDict) {
    this->s = s;
    int n = (int)wordDict.size();
    for (int i = 0; i < n; i++) {
      map[wordDict[i]] = 1;
    }

    string tmp;
    backtrace(tmp, 0, (int)s.size());
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> wordDict(n);
  for (int i = 0; i < n; i++) {
    cin >> wordDict[i];
  }

  Solution *so = new Solution;
  vector<string> res = so->wordBreak(s, wordDict);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
