#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

// struct trie {
// trie *children[26] = {NULL};
// bool isEnd = false;
// };

class Trie {
private:
  vector<Trie *> children;
  bool isEnd;

public:
  // constructor of this class
  Trie() {
    this->children.resize(26);
    this->isEnd = false;
  }

  Trie *searchPrefix(string prefix) {
    Trie *node = this;
    for (int i = 0; i < (int)prefix.length(); i++) {
      prefix[i] -= 'a';
      if (node->children[prefix[i]] == NULL) {
        return NULL;
      }
      node = node->children[prefix[i]];
    }
    return node;
  }

  void insert(string word) {
    // Trie is a class not a struct,
    // this is different from my used coding habits.
    Trie *node = new Trie;
    for (int i = 0; i < (int)word.length(); i++) {
      word[i] -= 'a';
      if (node->children[word[i]] == NULL) {
        node->children[word[i]] = new Trie();
      }
      node = node->children[word[i]];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    Trie *node = this->searchPrefix(word);
    return node != NULL && node->isEnd;
  }

  bool startsWith(string prefix) { return this->searchPrefix(prefix) != NULL; }
};

int main(int argc, char *argv[]) { return 0; }
