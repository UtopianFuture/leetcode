#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Tweet {
  int tweetId;
  int time;
  struct Tweet *next;
};

struct User {
  int userId;
  int followed[501];
  int follows_nums;
  struct Tweet *head;
};

typedef struct {
  struct Tweet *tweet;
  struct User *user[501];
  int timestamp;
} Twitter;

struct Tweet *mergeTwoLists(struct Tweet *list1, struct Tweet *list2) {
  struct Tweet *res = malloc(sizeof(struct Tweet));
  struct Tweet *next;

  next = res;
  while (list1 != NULL && list2 != NULL) {
    if (list1->time > list2->time) {
      next->next = list1;
      list1 = list1->next;
    } else {
      next->next = list2;
      list2 = list2->next;
    }
    next = next->next;
  }

  next->next = list1 == NULL ? list2 : list1;
  return res->next;
}

struct Tweet *mergeKLists(struct Tweet **lists, int listsSize) {
  if (listsSize == 0) {
    return NULL;
  }
  if (listsSize == 1) {
    return lists[0];
  }

  int k = 0;
  struct Tweet **res;
  if (listsSize % 2 == 1) {
    res = malloc((listsSize / 2 + 1) * sizeof(struct Tweet *));
    res[k++] = lists[listsSize - 1];
    for (int i = 0; i < listsSize - 1; i += 2) {
      res[k++] = mergeTwoLists(lists[i], lists[i + 1]);
    }
  } else {
    res = malloc((listsSize / 2) * sizeof(struct Tweet *));
    for (int i = 0; i < listsSize; i += 2) {
      res[k++] = mergeTwoLists(lists[i], lists[i + 1]);
    }
  }

  return mergeKLists(res, k);
}

Twitter *twitterCreate() {
  Twitter *twitter = malloc(sizeof(Twitter));
  memset(twitter->user, 0, sizeof(twitter->user));
  twitter->timestamp = 0;
  return twitter;
}

void twitterCreateUser(Twitter *obj, int userId) {
  struct User *user = malloc(sizeof(struct User));
  user->userId = userId;
  user->head = malloc(sizeof(struct Tweet));
  user->head->next = NULL;
  memset(user->followed, 0, sizeof(user->followed));
  user->follows_nums = 0;
  obj->user[userId] = user;
}

void twitterPostTweet(Twitter *obj, int userId, int tweetId) {
  if (obj->user[userId] == 0) {
    twitterCreateUser(obj, userId);
  }
  struct Tweet *tweet = malloc(sizeof(struct Tweet));
  tweet->time = obj->timestamp++;
  tweet->tweetId = tweetId;
  tweet->next = obj->user[userId]->head->next;
  obj->user[userId]->head->next = tweet;
}

int *twitterGetNewsFeed(Twitter *obj, int userId, int *retSize) {
  if (obj->user[userId] == 0) {
    return NULL;
  }
  int *followed = obj->user[userId]->followed;
  int follows_nums = obj->user[userId]->follows_nums;
  struct Tweet **res = malloc((1 + follows_nums) * sizeof(int *));
  // the first tweet list is userId's tweet list
  res[0] = obj->user[userId]->head->next;
  // find all followers' tweet list
  for (int i = 0; i < follows_nums; i++) {
    res[i + 1] = obj->user[followed[i]]->head->next;
  }

  struct Tweet *t = mergeKLists(res, follows_nums + 1);
  int *ans = malloc(10 * sizeof(int));
  (*retSize) = 0;
  while (t != NULL && (*retSize) < 10) {
    ans[(*retSize)++] = t->tweetId;
    t = t->next;
  }

  return ans;
}

void twitterFollow(Twitter *obj, int followerId, int followeeId) {
  if (obj->user[followerId] == 0) {
    twitterCreateUser(obj, followerId);
  }
  if (obj->user[followeeId] == 0) {
    twitterCreateUser(obj, followeeId);
  }

  struct User *user = obj->user[followerId];
  // follow this user, if not follow before
  for (int i = 0; i < user->follows_nums; i++) {
    if (user->followed[i] == followeeId) {
      return;
    }
  }
  user->followed[user->follows_nums++] = followeeId;
}

void twitterUnfollow(Twitter *obj, int followerId, int followeeId) {
  struct User *user = obj->user[followerId];
  // unfollow this user, if follow before
  for (int i = 0; i < user->follows_nums; i++) {
    if (user->followed[i] == followeeId) {
      user->followed[i] = 0;
      user->followed[i] = user->followed[user->follows_nums - 1];
      user->follows_nums--;
      return;
    }
  }
}

void twitterFree(Twitter *obj) { free(obj); }

int main() {
  // int *news = NULL;
  // Twitter *obj = twitterCreate();
  // twitterFollow(obj, 1, 5);
  // news = twitterGetNewsFeed(obj, 1, NULL);

  return 0;
}
