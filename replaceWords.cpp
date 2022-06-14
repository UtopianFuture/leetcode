#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Trie {
private:
  vector<Trie *> children;
  bool isEnd;

public:
  Trie() {
    this->children.resize(26);
    this->isEnd = false;
  }

  string search(string word) {
    Trie *node = this;
    string res;
    for (int i = 0; i < (int)word.length(); i++) {
      word[i] -= 'a';
      if (node->children[word[i]] == NULL) {
        return "";
      }
      res.push_back(word[i] + 'a');
      node = node->children[word[i]];
      // this is the last node
      if (node->isEnd) {
        break;
      }
    }
    return res;
  }

  void insert(string word) {
    Trie *node = this;
    for (int i = 0; i < (int)word.length(); i++) {
      word[i] -= 'a';
      if (node->children[word[i]] == NULL) {
        node->children[word[i]] = new Trie;
      }
      node = node->children[word[i]];
    }
    node->isEnd = true;
  }
};

class Solution {
public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    Trie *obj = new Trie;

    // build trie
    for (int i = 0; i < (int)dictionary.size(); i++) {
      obj->insert(dictionary[i]);
    }

    string tmp, tmp1;
    string res = "";
    // add a " " to the end of the sentence
    sentence += " ";
    for (char ch : sentence) {
      if (ch != ' ') {
        tmp.push_back(ch);
      } else {
        tmp1 = obj->search(tmp);
        if (tmp1 != "") {
          res += tmp1;
          res += " ";
        } else {
          res += tmp;
          res += " ";
        }
        tmp.clear();
      }
    }

    // erase the last " "
    res.erase(res.end() - 1, res.end());
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<string> dictionary;
  string tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    dictionary.push_back(tmp);
  }

  string sentence = "the cattle was rattled by the battery";
  Solution *s = new Solution;
  cout << s->replaceWords(dictionary, sentence) << "\n";

  return 0;
}
