#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int compareVersion(string version1, string version2) {
    string s1, s2;
    for (int i = 0; i < version1.size(); i++) {
      if (version1[i] == '.') {
        s1 += to_string(stoi(version1.substr(0, i)));
        version1.erase(version1.begin(), version1.begin() + i + 1);
        i = 0;
      }
    }
    s1 += to_string(stoi(version1));
    for (int i = 0; i < version2.size(); i++) {
      if (version2[i] == '.') {
        s2 += to_string(stoi(version2.substr(0, i)));
        version2.erase(version2.begin(), version2.begin() + i + 1);
        i = 0;
      }
    }
    s2 += to_string(stoi(version2));

    if (s1.size() > s2.size()) {
      int n = s1.size() - s2.size();
      for (int i = 0; i < n; i++) {
        s2 += "0";
      }
    } else if (s1.size() < s2.size()) {
      int n = s2.size() - s1.size();
      for (int i = 0; i < n; i++) {
        s1 += "0";
      }
    }
    if (s1 > s2) {
      return 1;
    } else if (s1 < s2) {
      return -1;
    } else {
      return 0;
    }
  }
};

class Solution1 {
public:
  int compareVersion(string version1, string version2) {
    int n1 = version1.size();
    int n2 = version2.size();
    int i1 = 0, i2 = 0;
    while (i1 < n1 || i2 < n2) {
      long x = 0;
      while (i1 < n1 && version1[i1] != '.') {
        x = x * 10 + version1[i1] - '0';
        i1++;
      }
      i1++;
      long y = 0;
      while (i2 < n2 && version2[i2] != '.') {
        y = y * 10 + version2[i2] - '0';
        i2++;
      }
      i2++;
      if (x > y) {
        return 1;
      } else if (x < y) {
        return -1;
      }
    }
    return 0;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s1, s2;
  cin >> s1 >> s2;

  Solution1 *s = new Solution1;
  cout << s->compareVersion(s1, s2) << endl;
  return 0;
}
