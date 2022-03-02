#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string multiply(string num1, string num2) {
    int size1 = (int)num1.size();
    int size2 = (int)num2.size();
    vector<int> tmp(size1 + size2, 0);

    int mul, sum;
    int p1, p2;
    for (int i = size1 - 1; i >= 0; i--) {
      for (int j = size2 - 1; j >= 0; j--) {
        mul = (num1[i] - '0') * (num2[j] - '0'); // num1[i] * num2[j]
        p1 = i + j; // result is in res[i + j] and res[i + j + 1]
        p2 = i + j + 1;
        sum = mul + tmp[p2]; // plus res[i+j+1]
        tmp[p1] += sum / 10;
        tmp[p2] = sum % 10;
      }
    }

    int i;
    for (i = 0; i < (int)tmp.size(); i++) {
      if (tmp[i] != 0) {
        break;
      }
    }

    string res;
    for (; i < (int)tmp.size(); i++) {
      res.push_back('0' + tmp[i]);
    }

    return (int)res.size() == 0 ? "0" : res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string num1, num2;
  cin >> num1 >> num2;

  Solution *s = new (Solution);
  string res = s->multiply(num1, num2);
  cout << res << "\n";

  return 0;
}
