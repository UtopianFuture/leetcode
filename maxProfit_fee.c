#include "stdio.h"
#include "stdlib.h"

int maxProfit(int *prices, int pricesSize, int fee) {
  int dp_0 = 0, dp_1 = -prices[0];
  int tmp = 0; // tmp save dp[i - 1]

  for (int i = 0; i < pricesSize; i++) {
    tmp = dp_0;
    dp_0 = dp_0 > dp_1 + prices[i] - fee ? dp_0 : dp_1 + prices[i] - fee;
    dp_1 = dp_1 > tmp - prices[i] ? dp_1 : tmp - prices[i];
  }

  return dp_0;
}

int main() {
  int pricesSize = 0;
  scanf("%d\n", &pricesSize);

  int fee = 0;
  scanf("%d\n", &fee);

  int *prices = malloc(pricesSize * sizeof(int));
  for (int i = 0; i < pricesSize; i++) {
    scanf("%d", &prices[i]);
  }

  printf("%d\n", maxProfit(prices, pricesSize, fee));
  return 0;
}

