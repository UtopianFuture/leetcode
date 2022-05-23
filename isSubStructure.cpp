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
  bool recur(TreeNode *a, TreeNode *b) {
    if (!b) {
      return true;
    }
    if (!a) {
      return false;
    }
    if (a->val != b->val) {
      return false;
    }
    return recur(a->left, b->left) && recur(a->right, b->right);
  }

  bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (!B || !A) {
      return false;
    }
    return recur(A, B) || isSubStructure(A->left, B) ||
           isSubStructure(A->right, B);
  }
};

int main(int argc, char *argv[]) { return 0; }
