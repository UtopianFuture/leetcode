#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  static bool cmp(string a, string b) { return a.size() > b.size(); }

  int minimumLengthEncoding(vector<string> &words) {
    unordered_map<string, int> map;
    string tmp;
    string res = "";

    sort(words.begin(), words.end(), cmp);
    for (auto word : words) {
      if (map[word]) {
        continue;
      } else {
        res += word + "#";
        for (int i = word.size() - 1; i >= 0; i--) {
          tmp = word.substr(i, word.size() - i);
          map[tmp] = 1;
        }
      }
    }
    return res.size();
  }
};

int main(int argc, char *argv[]) { return 0; }
