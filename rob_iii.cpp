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
  unordered_map<TreeNode *, int> visited;

public:
  int rob(TreeNode *root) {
    if (!root) {
      return 0;
    }

    if (visited[root]) {
      return visited[root];
    }

    int isrob =
        root->val +
        (root->left != NULL ? rob(root->left->left) + rob(root->left->right)
                            : 0) +
        (root->right != NULL ? rob(root->right->left) + rob(root->right->right)
                             : 0);
    int notrob = rob(root->left) + rob(root->right);
    int res = max(isrob, notrob);
    visited[root] = res;
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
