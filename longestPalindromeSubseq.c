#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int longestPalindromeSubseq(char *s) {
  int size = 0;
  while (s[size])
    size++;

  int dp[size][size];
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < size; i++) {
    dp[i][i] = 1;
  }
  for (int i = size - 1; i >= 0; i--) {
    for (int j = i + 1; j < size; j++) {
      if (s[i] == s[j]) {
        dp[i][j] = dp[i + 1][j - 1] + 2;
      } else {
        dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1];
      }
    }
  }

  return dp[0][size - 1];
}

int main() {
  char *s = malloc(1000 * sizeof(char));
  scanf("%s", s);

  printf("%d\n", longestPalindromeSubseq(s));
  return 0;
}
