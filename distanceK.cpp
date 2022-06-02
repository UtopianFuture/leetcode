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
  unordered_map<TreeNode *, TreeNode *> parent;

public:
  void preorder(TreeNode *root) {
    if (!root) {
      return;
    }
    if (root->left) {
      parent[root->left] = root;
    }
    if (root->right) {
      parent[root->right] = root;
    }
    preorder(root->left);
    preorder(root->right);
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    parent[root] = NULL;
    preorder(root);
    vector<int> res;
    int distance = 0;
    queue<TreeNode *> q;
    unordered_map<TreeNode *, int> visited;
    q.push(target);
    TreeNode *p;
    int n;
    while (!q.empty()) {
      n = (int)q.size();
      for (int i = 0; i < n; i++) {
        p = q.front();
        q.pop();
        visited[p] = 1;

        if (distance == k) {
          res.push_back(p->val);
        }

        if (parent[p] != NULL && visited[parent[p]] == 0) {
          visited[parent[p]] = 1;
          q.push(parent[p]);
        }
        if (p->left != NULL && visited[p->left] == 0) {
          visited[p->left] = 1;
          q.push(p->left);
        }
        if (p->right != NULL && visited[p->right] == 0) {
          visited[p->right] = 1;
          q.push(p->right);
        }
      }
      distance++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
