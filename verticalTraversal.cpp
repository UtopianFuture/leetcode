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
  unordered_map<int, vector<vector<int>>> m;
  int start = INT_MAX;
  int end = INT_MIN;

public:
  void preorder(TreeNode *root, int row, int column) {
    if (!root) {
      return;
    }

    start = min(column, start);
    end = max(column, end);
    m[column].push_back({row, root->val});
    preorder(root->left, row + 1, column - 1);
    preorder(root->right, row + 1, column + 1);
  }

  static bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
      return a[1] < b[1];
    }
    return a[0] < b[0];
  }

  vector<vector<int>> verticalTraversal(TreeNode *root) {
    vector<vector<int>> res;
    preorder(root, 0, 0);
    vector<vector<int>> tmpvv;
    for (int i = start; i <= end; i++) {
      tmpvv = m.find(i)->second;
      sort(tmpvv.begin(), tmpvv.end(), cmp);
      vector<int> tmpv;
      for (auto v : tmpvv) {
        tmpv.push_back(v[1]);
      }
      res.push_back(tmpv);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  TreeNode *root = new TreeNode(3);
  TreeNode *n1 = new TreeNode(9, NULL, NULL);
  TreeNode *n2 = new TreeNode(20);
  TreeNode *n3 = new TreeNode(15, NULL, NULL);
  TreeNode *n4 = new TreeNode(7, NULL, NULL);
  root->left = n1;
  root->right = n2;
  n2->left = n3;
  n2->right = n4;

  Solution *s = new Solution;
  vector<vector<int>> res = s->verticalTraversal(root);
  for (auto s1 : res) {
    for (auto s2 : s1) {
      cout << s2 << " ";
    }
    cout << "\n";
  }

  return 0;
}
