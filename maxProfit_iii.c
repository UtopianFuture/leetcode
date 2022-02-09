#include "stdio.h"
#include "stdlib.h"

int maxProfit(int *prices, int pricesSize) {
  // int dp_0 = 0, dp_1 = 0x80000001;
  int max_k = 2;
  int **dp_0 = malloc(pricesSize * sizeof(int *));
  int **dp_1 = malloc(pricesSize * sizeof(int *));
  for (int i = 0; i < pricesSize; i++) {
    dp_0[i] = malloc((max_k + 1) * sizeof(int));
    dp_1[i] = malloc((max_k + 1) * sizeof(int));
  }

  for (int i = 0; i < pricesSize; i++) {
    dp_0[i][0] = 0;
    dp_1[i][0] = -prices[i];
  }

  for (int i = 0; i < pricesSize; i++) {
    for (int k = 1; k <= max_k; k++) {
      if (i - 1 == -1) {
        dp_0[i][k] = 0;
        dp_1[i][k] = -prices[i];
        continue;
      }
      dp_0[i][k] = dp_0[i - 1][k] > dp_1[i - 1][k] + prices[i]
                       ? dp_0[i - 1][k]
                       : dp_1[i - 1][k] + prices[i];
      dp_1[i][k] = dp_1[i - 1][k] > dp_0[i - 1][k - 1] - prices[i]
                       ? dp_1[i - 1][k]
                       : dp_0[i - 1][k - 1] - prices[i];
    }
  }

  return dp_0[pricesSize - 1][max_k];
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
