#include "stdio.h"

int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

int main() {
  int n = 0;
  // for (int i = 0; i <= 30; i++) { // test 0 ~ 30
  //   printf("fib %d: %d\n", i, fib(i));
  // }
  scanf("%d", &n);
  printf("%d\n", fib(n));
  return 0;
}
