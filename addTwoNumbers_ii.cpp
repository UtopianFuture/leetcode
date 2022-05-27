#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<int> s1, s2;
    while (l1) {
      s1.push(l1->val);
      l1 = l1->next;
    }
    while (l2) {
      s2.push(l2->val);
      l2 = l2->next;
    }
    int carry = 0;
    ListNode *ans = nullptr;
    while (!s1.empty() || !s2.empty() || carry != 0) {
      int a = s1.empty() ? 0 : s1.top();
      int b = s2.empty() ? 0 : s2.top();
      if (!s1.empty())
        s1.pop();
      if (!s2.empty())
        s2.pop();
      int cur = a + b + carry;
      carry = cur / 10;
      cur %= 10;
      ListNode *curnode = new ListNode(cur);
      curnode->next = ans;
      ans = curnode;
    }
    return ans;
  }
};

class Solution1 {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode;
    vector<int> vl1, vl2, vres;
    while (l1) {
      vl1.insert(vl1.begin(), l1->val);
      l1 = l1->next;
    }
    while (l2) {
      vl2.insert(vl2.begin(), l2->val);
      l2 = l2->next;
    }

    int n1 = (int)vl1.size();
    int n2 = (int)vl2.size();
    int n = min(n1, n2);
    int carry = 0;
    for (int i = 0; i < n; i++) {
      vres.push_back(carry + (vl1[i] + vl2[i]) % 10);
      carry = (vl1[i] + vl2[i]) / 10;
    }

    if (n1 > n2) {
      vres.push_back((carry + vl1[n2]) % 10);
      carry = (carry + vl1[n2]) / 10;
      if (n2 + 1 < n1) {
        vres.push_back(vl1[n2 + 1] + carry);
      } else if (carry) {
        vres.push_back(carry);
      }
      for (int i = n2 + 2; i < n1; i++) {
        vres.push_back(vl1[i]);
      }
    } else if (n2 > n1) {
      vres.push_back((carry + vl2[n1]) % 10);
      carry = (carry + vl2[n1]) / 10;
      if (n1 + 1 < n2) {
        vres.push_back(vl2[n1 + 1] + carry);
      } else if (carry) {
        vres.push_back(carry);
      }
      for (int i = n1 + 2; i < n2; i++) {
        vres.push_back(vl2[i]);
      }
    } else {
      if (carry) {
        vres.push_back(carry);
      }
    }

    n = (int)vres.size();
    ListNode *p = res;
    for (int i = n - 1; i >= 0; i--) {
      ListNode *tmp = new ListNode;
      tmp->val = vres[i];
      p->next = tmp;
      p = p->next;
    }
    return res->next;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n1, n2;
  cin >> n1 >> n2;
  ListNode *l1 = new ListNode;
  ListNode *l2 = new ListNode;
  ListNode *p = l1, *q = l2;

  int tmp;
  for (int i = 0; i < n1; i++) {
    cin >> tmp;
    ListNode *ltmp = new ListNode;
    ltmp->val = tmp;
    p->next = ltmp;
    p = p->next;
  }
  for (int i = 0; i < n2; i++) {
    cin >> tmp;
    ListNode *ltmp = new ListNode;
    ltmp->val = tmp;
    q->next = ltmp;
    q = q->next;
  }

  Solution *s = new Solution;
  ListNode *res = s->addTwoNumbers(l1->next, l2->next);
  while (res) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << "\n";
  return 0;
}
