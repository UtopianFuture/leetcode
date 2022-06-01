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
  struct cmp {
    bool operator()(TreeNode *a, TreeNode *b) { return a->val < b->val; }
  };

  priority_queue<TreeNode *, vector<TreeNode *>, cmp> pq;
  unordered_map<int, int> m;

public:
  void preorder(TreeNode *root) {
    if (!root) {
      return;
    }

    if (m[root->val] == 0) {
      pq.push(root);
      if (pq.size() > 2) {
        pq.pop();
      }
    }
    m[root->val]++;
    preorder(root->left);
    preorder(root->right);
  }
  int findSecondMinimumValue(TreeNode *root) {
    preorder(root);
    if (pq.size() < 2) {
      return -1;
    }
    return pq.top()->val;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  TreeNode *root = new TreeNode(2);
  TreeNode *n1 = new TreeNode(2, NULL, NULL);
  TreeNode *n2 = new TreeNode(5);
  TreeNode *n3 = new TreeNode(5, NULL, NULL);
  TreeNode *n4 = new TreeNode(5, NULL, NULL);

  root->left = n1;
  root->right = n2;
  n2->left = n3;
  n2->right = n4;

  Solution *s = new Solution;
  s->findSecondMinimumValue(root);

  return 0;
}
