#include "stdio.h"
#include "stdlib.h"

// int min(int *dp, int size) {
//   int min_value = 0x7fffffff;
//   for (int i = 0; i < size; i++) {
//     if (dp[i] < min_value)
//       min_value = dp[i];
//   }
//   if (min_value == 0x7fffffff)
//     return min_value - 1;
//   return min_value;
// }

int coinChange(int *coins, int coinsSize, int amount) {
  if (amount == 0) {
    return 0;
  } else if (amount < 0) {
    return -1;
  }

  int min_value = 0x7fffffff;
  int val;
  // int *dp = malloc(coinsSize * sizeof(int));
  for (int i = 0; i < coinsSize; i++) {
    val = coinChange(coins, coinsSize, amount - coins[i]);
    if (val == -1) {
      continue;
    }
    min_value = min_value < (val + 1) ? min_value : (val + 1);
  }
  if (min_value != 0x7fffffff)
    return min_value;
  return -1;
}

int main() {
  int *coins = malloc(12 * sizeof(int));
  int amount = 0, size = 0;
  scanf("%d", &size);

  for (int i = 0; i < size; i++) {
    scanf("%d", &coins[i]);
  }

  scanf("%d", &amount);
  printf("%d\n", coinChange(coins, size, amount));
  return 0;
}
