#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Node {
public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

class Solution {
private:
  vector<Node *> tmp;

public:
  void inorder(Node *root) {
    if (!root) {
      return;
    }
    inorder(root->left);
    tmp.push_back(root);
    inorder(root->right);
  }

  Node *treeToDoublyList(Node *root) {
    if (!root) {
      return NULL;
    }
    inorder(root);
    int size = (int)tmp.size();
    if (size == 1) {
      tmp[0]->left = tmp[0];
      tmp[0]->right = tmp[0];
      return tmp[0];
    }
    for (int i = 0; i < size; i++) {
      if (i == 0) {
        tmp[i]->left = tmp[size - 1];
        tmp[i]->right = tmp[i + 1];
      } else if (i == size - 1) {
        tmp[i]->left = tmp[i - 1];
        tmp[i]->right = tmp[0];
      } else {
        tmp[i]->left = tmp[i - 1];
        tmp[i]->right = tmp[i + 1];
      }
    }
    return tmp[0];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  Node *root = new Node(1);
  // Node *n1 = new Node(2);
  // Node *n2 = new Node(1);
  // Node *n3 = new Node(3);
  // Node *n4 = new Node(5);
  // root->left = n1;
  // root->right = n4;
  // n1->left = n2;
  // n1->right = n3;

  Solution *s = new Solution;
  s->treeToDoublyList(root);
  return 0;
}
