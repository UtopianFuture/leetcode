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

  void insert(string s) {
    Trie *node = this;
    for (char c : s) {
      if (node->children[c - 'a'] == NULL) {
        node->children[c - 'a'] = new Trie;
      }
      node = node->children[c - 'a'];
    }
    node->isEnd = true;
  }

  void dfs(vector<string> &res, string &tmp, Trie *node, int n) {
    tmp.push_back(n + 'a');
    if (node->isEnd) {
      res.push_back(tmp);
    }
    for (int i = 0; i < 26; i++) {
      if (node->children[i]) {
        dfs(res, tmp, node->children[i], i);
      }
    }
  }

  vector<string> search(string s) {
    vector<string> res;
    string tmp;
    Trie *node = this;
    for (char c : s) {
      if (node->children[c - 'a'] == NULL) {
        return res;
      }
      tmp.push_back(c);
      node = node->children[c - 'a'];
    }

    if (node->isEnd) {
      res.push_back(tmp);
    }
    for (int i = 0; i < 26; i++) {
      if (node->children[i]) {
        dfs(res, tmp, node->children[i], i);
        tmp.pop_back();
      }
    }
    return res;
  }
};

class MapSum1 {
private:
  unordered_map<string, int> map;
  Trie *trie;

public:
  MapSum1() { this->trie = new Trie; }

  void insert(string key, int val) {
    if (map[key]) {
      map[key] = val;
    } else {
      trie->insert(key);
      map[key] = val;
    }
  }

  int sum(string prefix) {
    vector<string> pre = trie->search(prefix);
    int res = 0;
    for (int i = 0; i < (int)pre.size(); i++) {
      res += map[pre[i]];
    }
    return res;
  }
};

class MapSum {
private:
  unordered_map<string, int> map;

public:
  MapSum() {}

  void insert(string key, int val) { map[key] = val; }

  int sum(string prefix) {
    int res = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
      if (it->first.substr(0, prefix.size()) == prefix) {
        res += it->second;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  MapSum *mapsum = new MapSum;
  mapsum->insert("aa", 3);
  cout << mapsum->sum("a") << endl;
  mapsum->insert("ab", 2);
  cout << mapsum->sum("a") << endl;

  return 0;
}
