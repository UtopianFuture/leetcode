#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> levelOrder(TreeNode *root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *tmp;
    int n;
    while (!q.empty()) {
      n = q.size();
      for (int i = 0; i < n; i++) {
        tmp = q.front();
        q.pop();
        res.push_back(tmp->val);
        if (tmp->left) {
          q.push(tmp->left);
        }
        if (tmp->right) {
          q.push(tmp->right);
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
