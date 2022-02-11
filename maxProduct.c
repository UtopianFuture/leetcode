#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int max(int a, int b, int c) {
  int m = a > b ? a : b;
  return m > c ? m : c;
}

int min(int a, int b, int c) {
  int m = a < b ? a : b;
  return m < c ? m : c;
}

int maxProduct(int *nums, int numsSize) {
  int res = 0x80000001;
  int dp_max = 1;
  int dp_min = 1;

  int tmp = 0;
  for (int i = 0; i < numsSize; i++) {
    tmp = dp_max;
    dp_max = max(dp_max * nums[i], dp_min * nums[i], nums[i]);
    dp_min = min(tmp * nums[i], dp_min * nums[i], nums[i]);
    res = res > dp_max ? res : dp_max;
  }
  return res;
}

// out of time limited
// int maxProduct(int *nums, int numsSize) {
//   if (numsSize == 1) {
//     return nums[0];
//   }
//
//   int max = 0, sum = 1;
//   for (int i = 0; i < numsSize; i++) {
//     for (int j = i; j < numsSize; j++) {
//       sum *= nums[j];
//       max = max > sum ? max : sum;
//     }
//     sum = 1;
//   }
//   return max;
// }

int main() {
  int numsSize = 0;
  scanf("%d\n", &numsSize);

  int nums[numsSize];
  memset(nums, 0, sizeof(nums));
  for (int i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }

  printf("%d\n", maxProduct(nums, numsSize));
  return 0;
}
