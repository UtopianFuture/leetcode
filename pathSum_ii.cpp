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
  int res = 0;
  unordered_map<TreeNode *, TreeNode *> parent;

public:
  void checkSum(TreeNode *p, int targetSum) {
    int tmp = 0;
    while (p) {
      tmp += p->val;
      if (tmp == targetSum) {
        res++;
      }
      p = parent[p];
    }
  }

  int pathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return 0;
    }
    parent[root] = NULL;
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *p;
    while (!q.empty()) {
      p = q.front();
      q.pop();
      checkSum(p, targetSum);
      if (p->left) {
        parent[p->left] = p;
        q.push(p->left);
      }
      if (p->right) {
        parent[p->right] = p;
        q.push(p->right);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
