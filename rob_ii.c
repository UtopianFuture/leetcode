#include "stdio.h"
#include "stdlib.h"

int rob(int *nums, int numsSize) {
  int *dp = malloc(numsSize * sizeof(int));
  int max1 = 0, max2 = 0;

  if (numsSize == 1) {
    return nums[0];
  }
  if (numsSize == 2) {
    return nums[0] > nums[1] ? nums[0] : nums[1];
  }
  if (numsSize == 3) {
    int max = nums[0] > nums[1] ? nums[0] : nums[1];
    return max > nums[2] ? max : nums[2];
  }

  dp[0] = nums[0];
  dp[1] = nums[1];
  dp[2] = nums[2] + dp[0];
  for (int i = 3; i < numsSize - 1; i++) { // don't rob the last house
    dp[i] = dp[i - 2] > dp[i - 3] ? dp[i - 2] + nums[i] : dp[i - 3] + nums[i];
  }

  max1 =
      dp[numsSize - 2] > dp[numsSize - 3] ? dp[numsSize - 2] : dp[numsSize - 3];

  dp[1] = nums[1];
  dp[2] = nums[2];
  dp[3] = nums[3] + dp[1];
  for (int i = 4; i < numsSize; i++) { // don't rob the first house
    dp[i] = 0;
    dp[i] = dp[i - 2] > dp[i - 3] ? dp[i - 2] + nums[i] : dp[i - 3] + nums[i];
  }

  max2 =
      dp[numsSize - 1] > dp[numsSize - 2] ? dp[numsSize - 1] : dp[numsSize - 2];

  return max1 > max2 ? max1 : max2;
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
