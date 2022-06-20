#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isRectangleCover(vector<vector<int>> &rectangles) {
    typedef pair<int, int> Point;
    map<Point, int> m;
    int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
    long area = 0;
    for (auto rect : rectangles) {
      int x = rect[0], y = rect[1], a = rect[2], b = rect[3];
      area += (long)(a - x) * (long)(b - y);
      minX = min(x, minX);
      maxX = max(a, maxX);
      minY = min(y, minY);
      maxY = max(b, maxY);

      Point point1({x, y});
      Point point2({x, b});
      Point point3({a, y});
      Point point4({a, b});
      m[point1]++;
      m[point2]++;
      m[point3]++;
      m[point4]++;
    }

    Point minmin({minX, minY});
    Point minmax({minX, maxY});
    Point maxmin({maxX, minY});
    Point maxmax({maxX, maxY});
    if (area != (long)(maxX - minX) * (long)(maxY - minY) || !m[minmin] ||
        !m[minmax] || !m[maxmin] || !m[maxmax]) {
      return false;
    }

    m.erase(minmin);
    m.erase(minmax);
    m.erase(maxmin);
    m.erase(maxmax);
    for (auto p : m) {
      if (p.second != 2 && p.second != 4) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }
