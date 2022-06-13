#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool inArea(vector<vector<int>> &image, int row, int col) {
    return row >= 0 && row < (int)image.size() && col >= 0 &&
           col < (int)image[0].size();
  }

  void DFS(vector<vector<int>> &image, int row, int col, int origincolor,
           int newColor) {
    if (!inArea(image, row, col)) {
      return;
    }
    if (image[row][col] != origincolor) {
      return;
    }
    image[row][col] = -1; // [row, col] should not be check from it's neighbors
    DFS(image, row + 1, col, origincolor, newColor);
    DFS(image, row, col + 1, origincolor, newColor);
    DFS(image, row - 1, col, origincolor, newColor);
    DFS(image, row, col - 1, origincolor, newColor);
    image[row][col] = newColor;
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    int origincolor = image[sr][sc];
    DFS(image, sr, sc, origincolor, newColor);
    return image;
  }
};

int main(int argc, char *argv[]) { return 0; }
