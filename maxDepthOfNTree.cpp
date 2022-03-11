#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  int maxDepth(Node *root) {
    if (root == NULL) {
      return 0;
    }
    queue<Node *> q;
    q.push(root);
    int depth = 0;
    Node *p;
    int n;
    while (!q.empty()) {
      n = q.size();
      for (int i = 0; i < n; i++) {
        p = q.front();
        q.pop();
        for (int j = 0; j < (int)p->children.size(); j++) {
          q.push(p->children[j]);
        }
      }
      depth++;
    }
    return depth;
  }
};

int main(int argc, char *argv[]) { return 0; }
