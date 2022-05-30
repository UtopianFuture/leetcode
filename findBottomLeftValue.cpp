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
  int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    TreeNode *p;
    int n;
    while (!q.empty()) {
      n = q.size();
      for (int i = 0; i < n; i++) {
        p = q.front();
        q.pop();
        if (p->left != NULL) {
          q.push(p->left);
        }
        if (p->right != NULL) {
          q.push(p->right);
        }
      }
      depth++;
    }
    return depth;
  }

  int findBottomLeftValue(TreeNode *root) {
    int depth = maxDepth(root);
    queue<TreeNode *> q;
    q.push(root);
    int d = 0;
    TreeNode *p;
    int n;
    while (!q.empty()) {
      n = q.size();
      d++;
      for (int i = 0; i < n; i++) {
        p = q.front();
        q.pop();
        if (d == depth) {
          return p->val;
        }
        if (p->left != NULL) {
          q.push(p->left);
        }
        if (p->right != NULL) {
          q.push(p->right);
        }
      }
    }
    return 0;
  }
};

int main(int argc, char *argv[]) { return 0; }
