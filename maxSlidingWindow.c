#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize) {
  int q[numsSize];
  int head = 0, tail = 0;
  for (int i = 0; i < k; i++) {
    while (head < tail && nums[i] > nums[q[tail - 1]]) {
      tail--;
    }
    q[tail++] = i;
  }

  *returnSize = 0;
  int *res = malloc((numsSize - k + 1) * sizeof(int));
  res[(*returnSize)++] = nums[q[head]];
  for (int i = k; i < numsSize; i++) {
    while (head < tail && nums[i] >= nums[q[tail - 1]]) {
      tail--;
    }
    q[tail++] = i;
    while (q[head] <= i - k) {
      head++;
    }
    res[(*returnSize)++] = nums[q[head]];
  }

  return res;
}

int main() {
  int numsSize = 0, k = 0;
  scanf("%d\n", &numsSize);
  scanf("%d\n", &k);

  int *nums = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }

  int *returnSize = malloc((numsSize - k + 1) * sizeof(int));
  int *res = maxSlidingWindow(nums, numsSize, k, returnSize);
  for (int i = 0; i < numsSize - k + 1; i++) {
    printf("%d", res[i]);
    if (i == numsSize - k) {
      printf("\n");
    } else {
      printf(" ");
    }
  }

  return 0;
}
