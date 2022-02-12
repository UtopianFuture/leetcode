#include "stdio.h"

int climbStairs(int n){
  int pre, cur;
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  pre = 1;
  cur = 2;
  for (int i = 3; i < n + 1; i++){
    cur += pre;
    pre = cur - pre;
  }
  return cur;
}

int main(){
  int n;
  scanf("%d", &n);

  printf("%d\n", climbStairs(n));
  return 0;
}
