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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == NULL) {
      return res;
    }
    int depth = 0;
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *p;
    int n;
    while (!q.empty()) {
      n = q.size();
      vector<int> tmp;
      for (int i = 0; i < n; i++) {
        p = q.front();
        q.pop();
        if (depth % 2 == 0) {
          tmp.push_back(p->val);
        } else {
          tmp.insert(tmp.begin(), p->val);
        }
        if (p->left != NULL) {
          q.push(p->left);
        }
        if (p->right != NULL) {
          q.push(p->right);
        }
      }
      res.push_back(tmp);
      depth++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
