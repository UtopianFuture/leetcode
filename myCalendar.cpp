#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class MyCalendar {
private:
  vector<vector<int>> calendar;

public:
  MyCalendar() {}

  bool book(int start, int end) {
    int n = (int)calendar.size();
    if (n == 0) {
      calendar.push_back({{start, end}});
      return true;
    }

    for (int i = 0; i < n; i++) {
      if ((start <= calendar[i][0] && end >= calendar[i][1]) ||
          (start >= calendar[i][0] && start < calendar[i][1] &&
           end <= calendar[i][1]) ||
          (start < calendar[i][1] && end >= calendar[i][1]) ||
          (start <= calendar[i][0] && end <= calendar[i][1] &&
           end > calendar[i][0])) {
        return false;
      }
    }
    calendar.push_back({{start, end}});
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }
