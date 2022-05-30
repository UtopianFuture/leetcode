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

class CBTInserter {
private:
  TreeNode *root;
  queue<TreeNode *> ql;
  TreeNode *location = NULL;

public:
  CBTInserter(TreeNode *root) {
    queue<TreeNode *> q;
    this->root = root;
    q.push(root);
    TreeNode *p;
    while (!q.empty()) {
      p = q.front();
      q.pop();

      // reocrd nodes after the first suitable node
      if (!p->left || !p->right) {
        ql.push(p);
      }
      if (p->left) {
        q.push(p->left);
      } else if (!p->left && location == NULL) {
        location = p;
      }

      if (p->right) {
        q.push(p->right);
      } else if (!p->right && location == NULL) {
        location = p;
      }
    }
  }

  int insert(int v) {
    TreeNode *p = location;
    if (!p->left) {
      p->left = new TreeNode(v, NULL, NULL);
      ql.push(p->left);
      // update location
      location = p;
      return p->val;
    } else if (!p->right) {
      p->right = new TreeNode(v, NULL, NULL);
      ql.push(p->right);
      // we need pop the top node, because it already has left child and right
      // child.
      ql.pop();
      location = ql.front();
      return p->val;
    } else {
      return -1;
    }
  }

  TreeNode *get_root() { return root; }
};

int main(int argc, char *argv[]) { return 0; }
