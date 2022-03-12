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

class Codec1 {
private:
  string inorder;
  string postorder;

public:
  void getInorder(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    getInorder(root->left);
    inorder.push_back('0' + root->val);
    getInorder(root->right);
  }

  void getPostorder(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    getPostorder(root->left);
    getPostorder(root->right);
    postorder.push_back('0' + root->val);
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    TreeNode *in = root;
    TreeNode *post = root;
    getInorder(in);
    getPostorder(post);
    return inorder + postorder;
  }

  TreeNode *build(string inorder, string postorder, int inorder_left,
                  int inorder_right, int postorder_left, int postorder_right) {
    if (postorder_left > postorder_right || inorder_left > inorder_right) {
      return NULL;
    }

    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = postorder[postorder_right] - '0';
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

  TreeNode *buildTree(string inorder, string postorder) {
    return build(inorder, postorder, 0, (int)inorder.size() - 1, 0,
                 (int)postorder.size() - 1);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    int n1 = (int)data.size();
    int n2 = n1 / 2;
    string in = data.substr(0, n2);
    string post = data.substr(n2, n1);
    TreeNode *res;
    res = buildTree(in, post);
    return res;
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

class Codec {
public:
  void rserialize(TreeNode *root, string &str) {
    if (root == NULL) {
      str += "#,";
      return;
    }
    str += to_string(root->val) + ",";
    rserialize(root->left, str);
    rserialize(root->right, str);
  }

  string serialize(TreeNode *root) {
    string ret;
    rserialize(root, ret);
    return ret;
  }

  TreeNode *rdeserialize(list<string> &data) {
    if (data.front() == "#") {
      data.erase(data.begin());
      return NULL;
    }

    TreeNode *root = new TreeNode(stoi(data.front()));
    data.erase(data.begin());
    root->left = rdeserialize(data);
    root->right = rdeserialize(data);
    return root;
  }

  TreeNode *deserialize(string data) {
    list<string> array;
    string s;
    for (int i = 0; i < (int)data.size(); i++) {
      if (data[i] == ',') {
        array.push_back(s);
        s.clear();
      } else {
        s.push_back(data[i]);
      }
    }
    if (!s.empty()) {
      array.push_back(s);
      s.clear();
    }
    return rdeserialize(array);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int size;
  cin >> size;

  string inorder;
  string postorder;
  int tmp;
  for (int i = 0; i < size; i++) {
    cin >> tmp;
    inorder.push_back('0' + tmp);
  }

  for (int i = 0; i < size; i++) {
    cin >> tmp;
    postorder.push_back('0' + tmp);
  }

  Codec *s = new Codec;
  Codec1 *s1 = new Codec1;
  // TreeNode *root = s1->buildTree(inorder, postorder);
  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
  root->val = 3;
  TreeNode *n1 = (TreeNode *)malloc(sizeof(TreeNode));
  n1->val = 2;
  TreeNode *n2 = (TreeNode *)malloc(sizeof(TreeNode));
  n2->val = 4;
  TreeNode *n3 = (TreeNode *)malloc(sizeof(TreeNode));
  n3->val = 3;
  root->left = n1;
  root->right = n2;
  n1->left = n3;
  n1->right = NULL;
  n2->left = NULL;
  n2->right = NULL;
  n3->left = NULL;
  n3->right = NULL;
  string str = s->serialize(root);
  cout << str << "\n";
  TreeNode *d = s->deserialize(str);
  s1->test(d);

  return 0;
}
