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

class Build {
public:
  TreeNode *build(vector<int> &inorder, vector<int> &postorder,
                  int inorder_left, int inorder_right, int postorder_left,
                  int postorder_right) {
    if (postorder_left > postorder_right || inorder_left > inorder_right) {
      return NULL;
    }

    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = postorder[postorder_right];
    int root_index = inorder_left;
    for (int i = inorder_left; i <= inorder_right; i++) {
      if (inorder[i] == postorder[postorder_right]) {
        root_index = i;
        break;
      }
    }

    int size_left_subtree = root_index - inorder_left;
    root->left = build(inorder, postorder, inorder_left, root_index - 1,
                       postorder_left, postorder_left + size_left_subtree - 1);
    root->right =
        build(inorder, postorder, root_index + 1, inorder_right,
              postorder_left + size_left_subtree, postorder_right - 1);
    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return build(inorder, postorder, 0, (int)inorder.size() - 1, 0,
                 (int)postorder.size() - 1);
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

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *p = root;
    int n;
    while (!q.empty()) {
      n = (int)q.size();
      for (int i = 0; i < n; i++) {
        p = q.front();
        q.pop();
        res++;
        if (p->left != NULL) {
          q.push(p->left);
        }
        if (p->right != NULL) {
          q.push(p->right);
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int size;
  cin >> size;

  vector<int> inorder;
  vector<int> postorder;
  int tmp;
  for (int i = 0; i < size; i++) {
    cin >> tmp;
    inorder.push_back(tmp);
  }

  for (int i = 0; i < size; i++) {
    cin >> tmp;
    postorder.push_back(tmp);
  }

  int p, q;
  cin >> p >> q;
  TreeNode *P = (TreeNode *)malloc(sizeof(TreeNode));
  P->val = p;
  TreeNode *Q = (TreeNode *)malloc(sizeof(TreeNode));
  Q->val = q;
  Build *b = new Build;
  TreeNode *root = b->buildTree(inorder, postorder);
  b->test(root);
  cout << "\n";

  Solution *s = new Solution;
  cout << s->countNodes(root) << "\n";

  return 0;
}
