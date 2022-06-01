#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  unordered_map<int, int> m;

public:
  bool findTarget(TreeNode *root, int k) {
    if (!root) {
      return false;
    }

    if (m[k - root->val] == 1) {
      return true;
    }
    m[root->val] = 1;
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};

int main(int argc, char *argv[]) { return 0; }
