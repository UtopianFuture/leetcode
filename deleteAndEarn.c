#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int deleteAndEarn(int *nums, int numsSize) {
  int size = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > size)
      size = nums[i];
  }

  int dp[size + 1], sum[size + 1];
  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(sum));

  for (int i = 0; i < numsSize; i++) {
    sum[nums[i]] += nums[i];
  }

  if (size == 1) {
    return sum[1];
  }
  if (size == 2) {
    return sum[1] > sum[2] ? sum[1] : sum[2];
  }
  if (size == 3) {
    return sum[1] + sum[3] > sum[2] ? sum[1] + sum[3] : sum[2];
  }

  dp[0] = sum[0];
  dp[1] = sum[1];
  dp[2] = sum[2] + dp[0];
  for (int i = 3; i < size + 1; i++) {
    dp[i] = (dp[i - 2] > dp[i - 3] ? dp[i - 2] : dp[i - 3]) + sum[i];
  }
  return dp[size] > dp[size - 1] ? dp[size] : dp[size - 1];
}

int main() {
  int numsSize = 0;
  scanf("%d\n", &numsSize);

  int nums[numsSize];
  memset(nums, 0, sizeof(nums));
  for (int i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }

  printf("%d\n", deleteAndEarn(nums, numsSize));
  return 0;
}
