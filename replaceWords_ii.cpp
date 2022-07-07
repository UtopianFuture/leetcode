#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Trie {
private:
  vector<Trie *> child;
  bool isEnd;

public:
  Trie() {
    this->child.resize(26);
    this->isEnd = false;
  }

  void insert(string s) {
    Trie *node = this;
    int c;
    for (int i = 0; i < s.size(); i++) {
      c = s[i] - 'a';
      if (node->child[c] == NULL) {
        node->child[c] = new Trie();
      }
      node = node->child[c];
    }
    node->isEnd = true;
  }

  string search(string s) {
    Trie *node = this;
    string res;
    int c;
    for (int i = 0; i < s.size(); i++) {
      c = s[i] - 'a';
      if (node->child[c] != NULL) {
        node = node->child[c];
        res.push_back(c + 'a');
      } else {
        return "";
      }
      if (node->isEnd) {
        break;
      }
    }
    return res;
  }
};

class Solution {
public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    Trie *obj = new Trie;
    string res;
    for (auto d : dictionary) {
      obj->insert(d);
    }

    sentence += " ";
    string tmp, sub;
    for (int i = 0; i < sentence.size(); i++) {
      if (sentence[i] != ' ') {
        sub.push_back(sentence[i]);
      } else {
        tmp = obj->search(sub);
        if (tmp != "") {
          res += tmp + " ";
        } else {
          res += sub + " ";
        }
        sub.clear();
      }
    }

    res.erase(res.end() - 1, res.end());
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
