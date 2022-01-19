#include "stdio.h"

int fib(int n) {
  if (n == 1 || n == 2) {
    return 1;
  } else if (n == 0) {
    return 0;
  }
  int pre = 1, cur = 1;
  for (int i = 3; i <= n; i++) {
    cur += pre;
    pre = cur - pre;
  }
  return cur;
}

int main() {
  // int n = 0;
  for (int i = 0; i <= 30; i++) { // test 0 ~ 30
    printf("fib %d: %d\n", i, fib(i));
  }
  // scanf("%d", &n);
  // printf("%d\n", fib(n));
  return 0;
}
