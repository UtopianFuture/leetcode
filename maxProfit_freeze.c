#include "stdio.h"
#include "stdlib.h"

int maxProfit(int *prices, int pricesSize) {
  int dp_0 = 0, dp_1 = -prices[0];
  int tmp = 0, tmp2 = 0; // tmp save dp[i - 1], tmp2 save dp[i - 2]

  for (int i = 0; i < pricesSize; i++) {
    tmp2 = tmp;
    tmp = dp_0;
    dp_0 = dp_0 > dp_1 + prices[i] ? dp_0 : dp_1 + prices[i];
    dp_1 = dp_1 > tmp2 - prices[i] ? dp_1 : tmp2 - prices[i];
  }

  return dp_0;
}

int main() {
  int pricesSize = 0;
  scanf("%d\n", &pricesSize);

  int *prices = malloc(pricesSize * sizeof(int));
  for (int i = 0; i < pricesSize; i++) {
    scanf("%d", &prices[i]);
  }

  printf("%d\n", maxProfit(prices, pricesSize));
  return 0;
}
