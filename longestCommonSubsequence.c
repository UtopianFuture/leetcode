#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int longestCommonSubsequence(char *text1, char *text2) {
  int size1 = 0, size2 = 0;
  while (text1[size1])
    size1++;
  while (text2[size2])
    size2++;

  int dp[size1 + 1][size2 + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= size1; i++) {
    for (int j = 1; j <= size2; j++) {
      if (text1[i - 1] == text2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
      }
    }
  }

  return dp[size1][size2];
}

int main() {
  char *s = malloc(20 * sizeof(char));
  scanf("%s", s);

  char *p = malloc(30 * sizeof(char));
  scanf("%s", p);

  printf("%d\n", longestCommonSubsequence(s, p));
  return 0;
}
