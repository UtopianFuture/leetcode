#include "stdio.h"
#include "stdlib.h"

int rob(int *nums, int numsSize) {
  int *dp = malloc(numsSize * sizeof(int));

  if (numsSize == 1) {
    return nums[0];
  }
  if (numsSize == 2) {
    return nums[0] > nums[1] ? nums[0] : nums[1];
  }
  if (numsSize == 3) {
    return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
  }

  dp[0] = nums[0];
  dp[1] = nums[1];
  dp[2] = nums[2] + dp[0];
  for (int i = 3; i < numsSize; i++) {
    dp[i] = dp[i - 2] > dp[i - 3] ? dp[i - 2] + nums[i] : dp[i - 3] + nums[i];
  }

  return dp[numsSize - 1] > dp[numsSize - 2] ? dp[numsSize - 1]
                                             : dp[numsSize - 2];
}

int main() {
  int numsSize = 0;
  scanf("%d\n", &numsSize);

  int *nums = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }

  printf("%d\n", rob(nums, numsSize));
  return 0;
}
