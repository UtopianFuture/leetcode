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
public:
  vector<int> largestValues(TreeNode *root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *p;
    int m = INT_MIN;
    int n;
    while (!q.empty()) {
      n = (int)q.size();
      for (int i = 0; i < n; i++) {
        p = q.front();
        q.pop();
        m = max(m, p->val);
        if (p->left) {
          q.push(p->left);
        }
        if (p->right) {
          q.push(p->right);
        }
      }
      res.push_back(m);
      m = INT_MIN;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
