#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

bool stoneGame_one(int *piles, int pilesSize) {
  int dp[pilesSize][pilesSize];
  memset(dp, 0, sizeof(int));

  for (int i = 0; i < pilesSize; i++) {
    dp[i][i] = piles[i];
  }

  for (int i = pilesSize - 2; i >= 0; i--) {
    for (int j = i + 1; j < pilesSize; j++) {
      dp[i][j] = (piles[i] - dp[i + 1][j]) > (piles[j] - dp[i][j - 1])
                     ? (piles[i] - dp[i + 1][j])
                     : (piles[j] - dp[i][j - 1]);
    }
  }
  return dp[0][pilesSize - 1] > 0;
}

bool stoneGame_two(int *piles, int pilesSize) {
  int dp[pilesSize];

  for (int i = 0; i < pilesSize; i++) {
    dp[i] = piles[i];
  }

  for (int i = pilesSize - 2; i >= 0; i--) {
    for (int j = i + 1; j < pilesSize; j++) {
      dp[j] = (piles[i] - dp[j]) > (piles[j] - dp[j - 1])
                  ? (piles[i] - dp[j])
                  : (piles[j] - dp[j - 1]);
    }
  }
  return dp[pilesSize - 1] > 0;
}

int main() {
  int size = 0;
  scanf("%d", &size);

  int *piles = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    scanf("%d", &piles[i]);
  }

  if (stoneGame_two(piles, size))
    printf("true\n");
  else
    printf("false\n");
  return 0;
}
