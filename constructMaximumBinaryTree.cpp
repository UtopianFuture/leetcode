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
public:
  int findMax(vector<int> &nums, int start, int end) {
    int max = 0;
    int index;
    for (int i = start; i <= end; i++) {
      if (max < nums[i]) {
        index = i;
        max = nums[i];
      }
    }
    return index;
  }

  TreeNode *construct(vector<int> &nums, int start, int end) {
    if (start == end) {
      TreeNode *n = new TreeNode;
      n->val = nums[start];
      n->left = NULL;
      n->right = NULL;
      return n;
    }

    int i = findMax(nums, start, end);
    TreeNode *n = new TreeNode;
    n->val = nums[i];
    if (i > start) {
      n->left = construct(nums, start, i - 1);
    } else {
      n->left = NULL;
    }
    if (i < end) {
      n->right = construct(nums, i + 1, end);
    } else {
      n->right = NULL;
    }
    return n;
  }

  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return construct(nums, 0, (int)nums.size() - 1);
  }

  void test(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    cout << root->val << " ";
    test(root->left);
    test(root->right);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> nums;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }

  Solution *s = new Solution;
  TreeNode *res = s->constructMaximumBinaryTree(nums);
  s->test(res);
  return 0;
}
