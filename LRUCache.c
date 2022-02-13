#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node {
  int value;
  int key;
  struct node *next, *prev;
} node;

typedef struct {
  struct node *value_location[10001];
  int used;
  int capacity;
  struct node *head, *tail;
} LRUCache;

void addToHead(LRUCache *obj, struct node *n) {
  n->next = obj->head->next;
  n->prev = obj->head;
  obj->head->next->prev = n;
  obj->head->next = n;
}

void removeFromTail(LRUCache *obj) {
  struct node *tmp = obj->tail->prev;
  obj->tail->prev->prev->next = obj->tail;
  obj->tail->prev = obj->tail->prev->prev;
  obj->value_location[tmp->key] = 0;
  free(tmp);
}

void removeNode(struct node *n) {
  n->prev->next = n->next;
  n->next->prev = n->prev;
}

LRUCache *lRUCacheCreate(int capacity) {
  LRUCache *cache = malloc(sizeof(LRUCache));
  cache->capacity = capacity;
  cache->used = 0;
  // cache->value_location = malloc(10000 * sizeof(struct node *));
  memset(cache->value_location, 0, sizeof(cache->value_location));
  cache->head = malloc(sizeof(node));
  cache->tail = malloc(sizeof(node));
  cache->head->next = cache->tail;
  cache->tail->prev = cache->head;
  return cache;
}

int lRUCacheGet(LRUCache *obj, int key) {
  if (obj->value_location[key] == 0) {
    return -1;
  } else {
    removeNode(obj->value_location[key]);
    addToHead(obj, obj->value_location[key]);
    return obj->value_location[key]->value;
  }
}

void lRUCachePut(LRUCache *obj, int key, int value) {
  if (obj->value_location[key]) { // key - value already in cache
    obj->value_location[key]->value = value;
    removeNode(obj->value_location[key]);
    addToHead(obj, obj->value_location[key]);
  } else {                           // key - value not in cache
    if (obj->used < obj->capacity) { // cache not fill
      struct node *n = malloc(sizeof(node));
      n->value = value;
      n->key = key;
      addToHead(obj, n);
      obj->value_location[key] = n;
      obj->used++;
    } else { // cache fill
      obj->value_location[obj->tail->prev->key] = 0;
      removeFromTail(obj);
      struct node *n = malloc(sizeof(node));
      n->value = value;
      n->key = key;
      obj->value_location[key] = n;
      addToHead(obj, n);
    }
  }
}

void lRUCacheFree(LRUCache *obj) { free(obj); }

int main() {
  int capacity = 0;
  scanf("%d\n", &capacity);

  // int value;
  // LRUCache *cache = lRUCacheCreate(capacity);
  // lRUCachePut(cache, 1, 1);
  // lRUCachePut(cache, 2, 2);
  // value = lRUCacheGet(cache, 1);
  // lRUCachePut(cache, 3, 3);
  // value = lRUCacheGet(cache, 2);
  // lRUCachePut(cache, 4, 4);
  // value = lRUCacheGet(cache, 1);
  // value = lRUCacheGet(cache, 3);
  // value = lRUCacheGet(cache, 4);
  return 0;
}
