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
private:
  vector<int> res;

public:
  vector<int> preorder(Node *root) {
    if (root == NULL) {
      return res;
    }
    res.push_back(root->val);
    for (int i = 0; i < (int)root->children.size(); i++) {
      preorder(root->children[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
