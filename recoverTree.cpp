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
  vector<TreeNode *> tmp;

public:
  void inorder(TreeNode *root) {
    if (!root) {
      return;
    }
    inorder(root->left);
    tmp.push_back(root);
    inorder(root->right);
  }

  void reverse() {
    int n = (int)tmp.size();
    int count = 0;
    int x = -1, y = -1;

    if (tmp[0]->val > tmp[1]->val) {
      x = 0;
      count++;
    }
    if (tmp[n - 1]->val < tmp[n - 2]->val) {
      count++;
      if (x == -1) {
        x = n - 1;
      } else {
        y = n - 1;
      }
    }

    for (int i = 1; i < n - 1; i++) {
      if (count < 2 &&
          !(tmp[i]->val > tmp[i - 1]->val && tmp[i]->val < tmp[i + 1]->val)) {
        count++;
        if (x == -1) {
          x = i;
          i++;
        } else {
          y = i;
          i++;
        }
      }
    }

    if (count == 1) {
      int t = tmp[x]->val;
      tmp[x]->val = tmp[x + 1]->val;
      tmp[x + 1]->val = t;
    } else {
      int t = tmp[x]->val;
      tmp[x]->val = tmp[y]->val;
      tmp[y]->val = t;
    }
  }
  void recoverTree(TreeNode *root) {
    inorder(root);
    reverse();
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  TreeNode *root = new TreeNode(146);
  TreeNode *n1 = new TreeNode(71);
  TreeNode *n2 = new TreeNode(-13);
  TreeNode *n3 = new TreeNode(55);
  TreeNode *n4 = new TreeNode(231, NULL, NULL);
  TreeNode *n5 = new TreeNode(399, NULL, NULL);
  TreeNode *n6 = new TreeNode(321);
  TreeNode *n7 = new TreeNode(-33, NULL, NULL);

  root->left = n1;
  root->right = n2;
  n1->left = n3;
  n1->right = NULL;
  n2->left = n4;
  n2->right = n5;
  n3->left = n6;
  n3->right = NULL;
  n6->left = n7;
  n6->right = NULL;

  Solution *s = new Solution;
  s->recoverTree(root);
  return 0;
}
