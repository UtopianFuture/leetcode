#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int maxSubArray(int *nums, int numsSize) {
  int max = -10001;
  int dp = -10001;

  for (int i = 0; i < numsSize; i++) {
    dp = nums[i] > nums[i] + dp ? nums[i] : nums[i] + dp;
    max = max > dp ? max : dp;
  }

  return max;
}

int main() {
  int numsSize = 0;
  scanf("%d\n", &numsSize);

  int nums[numsSize];
  memset(nums, 0, sizeof(nums));
  for (int i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }

  printf("%d\n", maxSubArray(nums, numsSize));
  return 0;
}
