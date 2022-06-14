#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class LRUCache {
private:
  struct node {
    int val;
    int key;
    struct node *next;
    struct node *prev;
  };
  struct node *head, *tail;
  unordered_map<int, node *> map;
  int capacity;
  int used;

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->used = 0;
    // add dummy and tail to simplify operation
    struct node *dummy = new node;
    struct node *tail = new node;
    dummy->next = tail;
    tail->prev = dummy;
    this->head = dummy;
    this->tail = tail;
  }

  int get(int key) {
    if (map[key]) {
      // this node is exist, move it to head
      map[key]->prev->next = map[key]->next;
      map[key]->next->prev = map[key]->prev;
      map[key]->next = head->next;
      head->next->prev = map[key];
      head->next = map[key];
      map[key]->prev = head;
      return map[key]->val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (map[key]) {
      map[key]->prev->next = map[key]->next;
      map[key]->next->prev = map[key]->prev;
      map[key]->next = head->next;
      head->next->prev = map[key];
      head->next = map[key];
      map[key]->prev = head;
      map[key]->val = value;
    } else {
      // insert new node in head
      struct node *tmp = new node;
      tmp->key = key;
      tmp->val = value;
      tmp->next = head->next;
      head->next->prev = tmp;
      tmp->prev = head;
      head->next = tmp;
      map[key] = tmp;
      this->used++;
      if (used > capacity) {
        // deleta last node
        map[tail->prev->key] = NULL;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        this->used--;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int capacity;
  cin >> capacity;

  int value;
  LRUCache *cache = new LRUCache(capacity);
  cache->put(1, 1);
  cache->put(2, 2);
  value = cache->get(1);
  cout << value;
  cache->put(3, 3);
  value = cache->get(2);
  cache->put(4, 4);
  value = cache->get(1);
  value = cache->get(3);
  value = cache->get(4);

  return 0;
}
