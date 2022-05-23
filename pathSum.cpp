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
  vector<vector<int>> res;
  unordered_map<TreeNode *, TreeNode *> parent;

public:
  void getPath(TreeNode *node) {
    vector<int> tmp;
    while (node) {
      tmp.insert(tmp.begin(), node->val);
      node = parent[node];
    }
    res.push_back(tmp);
  }

  vector<vector<int>> pathSum(TreeNode *root, int target) {
    if (!root) {
      return res;
    }

    parent[root] = NULL;
    queue<TreeNode *> q_node;
    queue<int> q_val;
    q_node.push(root);
    q_val.push(0);
    TreeNode *tmp;
    while (!q_node.empty()) {
      tmp = q_node.front();
      int val = tmp->val + q_val.front();
      q_node.pop();
      q_val.pop();
      if (tmp->left == NULL && tmp->right == NULL) {
        if (val == target) {
          getPath(tmp);
        }
      } else {
        if (tmp->left) {
          parent[tmp->left] = tmp;
          q_node.push(tmp->left);
          q_val.push(val);
        }
        if (tmp->right) {
          parent[tmp->right] = tmp;
          q_node.push(tmp->right);
          q_val.push(val);
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
