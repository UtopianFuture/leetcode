#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class WordDictionary {
private:
  vector<WordDictionary *> children;
  bool isEnd;

public:
  WordDictionary() {
    this->children.resize(26);
    this->isEnd = false;
  }

  void addWord(string word) {
    WordDictionary *node = this;
    for (char ch : word) {
      ch -= 'a';
      if (node->children[ch] == NULL) {
        node->children[ch] = new WordDictionary;
      }
      node = node->children[ch];
    }
    node->isEnd = true;
  }

  bool dfs(string word, WordDictionary *node) {
    char ch;
    while (!word.empty()) {
      ch = word[0];
      if (ch != '.') {
        ch -= 'a';
        if (node->children[ch] == NULL) {
          return false;
        }
        node = node->children[ch];
        word.erase(word.begin(), word.begin() + 1);
      } else {
        for (int i = 0; i < 26; i++) {
          ch = i;
          if (node->children[ch] != NULL) {
            // word.erase(word.begin(), word.begin() + 1);
            if (dfs(word.substr(1, word.length() - 1), node->children[ch])) {
              return true;
            }
          }
        }
        return false;
      }
    }
    if (node != NULL && !node->isEnd) {
      return false;
    }
    return true;
  }

  bool search(string word) {
    WordDictionary *node = this;
    return dfs(word, node);
  }
};

int main(int argc, char *argv[]) {
  WordDictionary *wordDictionary = new WordDictionary();
  wordDictionary->addWord("at");
  wordDictionary->addWord("and");
  wordDictionary->addWord("an");
  wordDictionary->addWord("add");
  if (wordDictionary->search("a")) { // return False
    cout << "true"
         << "\n";
  } else {
    cout << "false"
         << "\n";
  }
  if (wordDictionary->search(".at")) { // return True
    cout << "true"
         << "\n";
  } else {
    cout << "false"
         << "\n";
  }
  wordDictionary->addWord("bat");
  if (wordDictionary->search(".at")) { // return True
    cout << "true"
         << "\n";
  } else {
    cout << "false"
         << "\n";
  }
  if (wordDictionary->search("an.")) { // return True
    cout << "true"
         << "\n";
  } else {
    cout << "false"
         << "\n";
  }
  if (wordDictionary->search("a.d.")) { // return True
    cout << "true"
         << "\n";
  } else {
    cout << "false"
         << "\n";
  }
  if (wordDictionary->search("b.")) { // return True
    cout << "true"
         << "\n";
  } else {
    cout << "false"
         << "\n";
  }
  if (wordDictionary->search("a.d")) { // return True
    cout << "true"
         << "\n";
  } else {
    cout << "false"
         << "\n";
  }
  if (wordDictionary->search(".")) { // return True
    cout << "true"
         << "\n";
  } else {
    cout << "false"
         << "\n";
  }
  return 0;
}
