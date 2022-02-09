#include "stdio.h"
#include "stdlib.h"

int maxProfit_inf(int *prices, int pricesSize) {
  int dp_0 = 0, dp_1 = 0x80000001;
  int temp = 0;

  for (int i = 0; i < pricesSize; i++) {
    temp = dp_0;
    dp_0 = dp_0 > dp_1 + prices[i] ? dp_0 : dp_1 + prices[i];
    dp_1 = dp_1 > temp - prices[i] ? dp_1 : dp_0 - prices[i];
  }
  return dp_0;
}

int maxProfit(int k, int *prices, int pricesSize) {
  // int dp_0 = 0, dp_1 = 0x80000001;
  int **dp_0 = malloc(pricesSize * sizeof(int *));
  int **dp_1 = malloc(pricesSize * sizeof(int *));
  for (int i = 0; i < pricesSize; i++) {
    dp_0[i] = malloc((k + 1) * sizeof(int));
    dp_1[i] = malloc((k + 1) * sizeof(int));
  }

  if (k > pricesSize / 2) {
    return maxProfit_inf(prices, pricesSize);
  }

  for (int i = 0; i < pricesSize; i++) {
    dp_0[i][0] = 0;
    dp_1[i][0] = -prices[i];
  }
  for (int i = 0; i < pricesSize; i++) {
    for (int j = 1; j <= k; j++) {
      if (i - 1 == -1) {
        dp_0[i][j] = 0;
        dp_1[i][j] = -prices[i];
        continue;
      }
      dp_0[i][j] = dp_0[i - 1][j] > dp_1[i - 1][j] + prices[i]
                       ? dp_0[i - 1][j]
                       : dp_1[i - 1][j] + prices[i];
      dp_1[i][j] = dp_1[i - 1][j] > dp_0[i - 1][j - 1] - prices[i]
                       ? dp_1[i - 1][j]
                       : dp_0[i - 1][j - 1] - prices[i];
    }
  }

  return dp_0[pricesSize - 1][k];
}

int main() {
  int pricesSize = 0;
  scanf("%d\n", &pricesSize);

  int k = 0;
  scanf("%d\n", &k);

  int *prices = malloc(pricesSize * sizeof(int));
  for (int i = 0; i < pricesSize; i++) {
    scanf("%d", &prices[i]);
  }

  printf("%d\n", maxProfit(k, prices, pricesSize));
  return 0;
}
