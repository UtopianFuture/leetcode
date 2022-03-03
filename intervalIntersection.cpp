#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    vector<vector<int>> list;
    vector<vector<int>> res;
    int size1 = (int)firstList.size();
    int size2 = (int)secondList.size();
    if (size1 == 0 || size2 == 0) {
      return {};
    }
    int i = 0, j = 0;
    // merge to list
    while (i < size1 || j < size2) {
      if (firstList[i][0] < secondList[j][0]) {
        list.push_back(firstList[i]);
        i++;
      } else {
        list.push_back(secondList[j]);
        j++;
      }
      if (i == size1) {
        while (j < size2) {
          list.push_back(secondList[j]);
          j++;
        }
        break;
      }
      if (j == size2) {
        while (i < size1) {
          list.push_back(firstList[i]);
          i++;
        }
        break;
      }
    }

    int max = 0;
    int next = 0, tmp = 0;
    for (int i = 0; i < size1 + size2; i++) {
      max = list[i][1];
      next = i + 1;
      while (next < (size1 + size2) && list[next][0] <= max) {
        tmp = list[next][1] < max ? list[next][1] : max;
        res.push_back({list[next][0], tmp});
        next++;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  vector<vector<int>> firstList;
  vector<vector<int>> secondList;
  int tmp1, tmp2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp1 >> tmp2;
    firstList.push_back({tmp1, tmp2});
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp1 >> tmp2;
    secondList.push_back({tmp1, tmp2});
  }

  Solution *s = new (Solution);
  vector<vector<int>> res = s->intervalIntersection(firstList, secondList);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i][0] << " " << res[i][1] << "\n";
  }

  return 0;
}
