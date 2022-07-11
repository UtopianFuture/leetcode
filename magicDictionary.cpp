#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Trie {
private:
  bool isEnd;
  vector<Trie *> children;
  int count;

public:
  Trie() {
    this->isEnd = false;
    this->children.resize(26);
    this->count = 0;
  }

  void insert(string s) {
    Trie *node = this;
    int tmp;
    for (int i = 0; i < s.size(); i++) {
      tmp = s[i] - 'a';
      if (node->children[tmp] == NULL) {
        node->children[tmp] = new Trie;
      }
      node = node->children[tmp];
    }
    node->isEnd = true;
  }

  bool search(string s) {
    Trie *node = this;
    int tmp;
    int i = 0;
    for (; i < s.size(); i++) {
      tmp = s[i] - 'a';
      if (node->children[tmp] == NULL) {
        if (count == 0) {
          for (int j = 0; j < 26; j++) {
            if (node->children[j]) {
              node->children[j]->count++;
              s[i] = j + 'a'; // replace a char
              if (node->children[j]->search(
                      s.substr(i + 1, s.size() - i - 1))) {
                return true;
              } else {
                count--;
              }
            }
          }
          return false;
        } else {
          return false;
        }
      }
      node = node->children[tmp];
      if (node->isEnd) {
        break;
      }
    }
    if (i == s.size() - 1) {
      if (this->count == 1) {
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
};

class MagicDictionary1 {
private:
  Trie *node;

public:
  MagicDictionary1() { node = new Trie; }

  void buildDict(vector<string> dictionary) {
    for (auto word : dictionary) {
      node->insert(word);
    }
  }

  bool search(string searchWord) { return node->search(searchWord); }
};

class MagicDictionary {
private:
  vector<string> words;

public:
  MagicDictionary() {}

  void buildDict(vector<string> dictionary) {
    for (auto word : dictionary) {
      words.push_back(word);
    }
  }

  bool search(string searchWord) {
    int diff = 0;
    for (auto word : words) {
      if (searchWord.size() == word.size()) {
        for (int i = 0; i < word.size(); i++) {
          if (searchWord[i] != word[i]) {
            diff++;
            if (diff > 1) {
              diff = 0;
              break;
            }
          }
        }
        if (diff == 1) {
          break;
        }
      }
    }
    return diff == 1;
  }
};

int main(int argc, char *argv[]) {
  MagicDictionary *obj = new MagicDictionary();
  vector<string> dictionary;
  dictionary.push_back("hello");
  dictionary.push_back("leetcode");
  dictionary.push_back("hallo");
  obj->buildDict(dictionary);
  string searchWord;
  searchWord = "hello";
  bool param_2 = obj->search(searchWord);
  cout << param_2 << endl;
  searchWord = "hhllo";
  param_2 = obj->search(searchWord);
  cout << param_2 << endl;
  searchWord = "hell";
  param_2 = obj->search(searchWord);
  cout << param_2 << endl;
  searchWord = "leetcoded";
  param_2 = obj->search(searchWord);
  cout << param_2 << endl;

  return 0;
}
