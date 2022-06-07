#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  TreeNode *construct(ListNode *head) {
    if (!head) {
      return NULL;
    }
    if (!head->next) {
      return new TreeNode(head->val);
    }

    ListNode *one = head;
    ListNode *two = head;
    ListNode *pre;
    while (two && two->next) {
      pre = one;
      one = one->next;
      two = two->next;
      if (two) {
        two = two->next;
      }
    }

    ListNode *right = one->next;
    pre->next = NULL;
    TreeNode *root = new TreeNode(one->val);
    root->left = construct(head);
    root->right = construct(right);
    return root;
  }

  TreeNode *sortedListToBST(ListNode *head) { return construct(head); }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  int tmp;
  ListNode *l = new ListNode();
  ListNode *p = l;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    ListNode *tmpl = new ListNode(tmp);
    p->next = tmpl;
    p = tmpl;
  }

  Solution *s = new Solution;
  s->sortedListToBST(l->next);
  return 0;
}
