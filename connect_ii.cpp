#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    queue<Node *> q;
    if (root == NULL) {
      return root;
    }
    q.push(root);
    Node *p;
    int n;
    while (!q.empty()) {
      n = q.size();
      for (int i = 0; i < n; i++) {
        p = q.front();
        q.pop();
        if (i != n - 1) {
          p->next = q.front();
        } else {
          p->next = NULL;
        }
        if (p->left != NULL) {
          q.push(p->left);
        }
        if (p->right != NULL) {
          q.push(p->right);
        }
      }
    }
    return root;
  }
};

int main(int argc, char *argv[]) { return 0; }
