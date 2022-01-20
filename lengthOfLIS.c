#include "stdio.h"
#include "stdlib.h"

int lengthOfLIS(int *nums, int numsSize) {
  int *dp = malloc(numsSize * sizeof(int));
  int val1 = 0, val2 = 0;
  int max = 0;

  for (int i = 0; i < numsSize; i++) {
    dp[i] = 1;
  }

  for (int i = 0; i < numsSize; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        val1 = dp[j] + 1;
      }
      val2 = val1 > val2 ? val1 : val2;
    }
    dp[i] = val2 > dp[i] ? val2 : dp[i];
    val1 = 0;
    val2 = 0;
    max = max > dp[i] ? max : dp[i];
  }
  return max;
}

int main() {
  int size;
  scanf("%d", &size);

  int *nums = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    scanf("%d", &nums[i]);
  }

  printf("max length: %d\n", lengthOfLIS(nums, size));
  return 0;
}
