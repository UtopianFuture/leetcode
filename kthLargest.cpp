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
private:
  vector<int> res;

public:
  void inorder(TreeNode *root) {
    if (!root) {
      return;
    }
    inorder(root->left);
    res.push_back(root->val);
    inorder(root->right);
  }
  int kthLargest(TreeNode *root, int k) {
    inorder(root);

    return res[(int)res.size() - k];
  }
};

int main(int argc, char *argv[]) { return 0; }
