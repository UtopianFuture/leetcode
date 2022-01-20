#include "stdio.h"
#include "stdlib.h"

// int coinChange(int *coins, int coinsSize, int amount) {
//   if (amount == 0) {
//     return 0;
//   } else if (amount < 0) {
//     return -1;
//   }
//
//   int min_value = 0x7fffffff;
//   int val;
//   // int *dp = malloc(coinsSize * sizeof(int));
//   for (int i = 0; i < coinsSize; i++) {
//     val = coinChange(coins, coinsSize, amount - coins[i]);
//     if (val == -1) {
//       continue;
//     }
//     min_value = min_value < (val + 1) ? min_value : (val + 1);
//   }
//   if (min_value != 0x7fffffff)
//     return min_value;
//   return -1;
// }

int coinChange(int *coins, int coinsSize, int amount) {
  int *dp = malloc((amount + 1) * sizeof(int));
  for (int i = 0; i < amount + 1; i++) {
    dp[i] = amount + 1;
  }

  dp[0] = 0;
  for (int i = 0; i < amount + 1; i++) {
    for (int j = 0; j < coinsSize; j++) {
      if (i - coins[j] < 0)
        continue;
      dp[i] = (dp[i] < (dp[i - coins[j]] + 1)) ? dp[i] : (dp[i - coins[j]] + 1);
    }
  }
  return dp[amount] != amount + 1 ? dp[amount] : -1;
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
