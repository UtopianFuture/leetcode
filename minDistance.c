#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int minDistance(char *word1, char *word2) {
  int size1 = 0, size2 = 0;
  int min = 0x7fffffff;
  while (word1[size1])
    size1++;
  while (word2[size2])
    size2++;

  int **dp = malloc((size1 + 1) * sizeof(int *));
  for (int i = 0; i < size1 + 1; i++) {
    dp[i] = malloc((size2 + 1) * sizeof(int));
  }

  for (int i = 0; i < size2 + 1; i++) {
    dp[0][i] = i;
  }
  for (int i = 0; i < size1 + 1; i++) {
    dp[i][0] = i;
  }

  for (int i = 1; i < size1 + 1; i++) {
    for (int j = 1; j < size2 + 1; j++) {
      if (word1[i - 1] == word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        min = (dp[i - 1][j] + 1) < (dp[i][j - 1] + 1) ? (dp[i - 1][j] + 1)
                                                      : (dp[i][j - 1] + 1);
        dp[i][j] = min < (dp[i - 1][j - 1] + 1) ? min : (dp[i - 1][j - 1] + 1);
        min = 0x7fffffff;
      }
    }
  }
  return dp[size1][size2];
}

int main() {
  char *word1 = malloc(500 * sizeof(char)), *word2 = malloc(500 * sizeof(char));
  scanf("%s", word1);
  scanf("%s", word2);

  printf("minDistance: %d\n", minDistance(word1, word2));
  return 0;
}
