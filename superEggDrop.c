#include "stdio.h"
#include "stdlib.h"

int superEggDrop_kn(int k, int n) {
  int **dp = malloc((n + 1) * sizeof(int *));
  for (int i = 0; i < n + 1; i++) {
    dp[i] = malloc((k + 1) * sizeof(int));
  }

  if (n == 1) {
    return 1;
  }

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < k + 1; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i < k + 1; i++) {
    dp[1][i] = 1;
  }

  int ans = -1;
  for (int i = 2; i < n + 1; i++) { // 最多测试 n + 1 次
    for (int j = 1; j < k + 1; j++) {
      dp[i][j] = 1 + dp[i - 1][j - 1] + dp[i - 1][j];
    }
    if (dp[i][k] >= n) {
      ans = i;
      break;
    }
  }
  return ans;
}

int superEggDrop_nn(int k, int n) {
  int **dp = malloc((n + 1) * sizeof(int *));
  int mid = 0;
  int val1 = 0x7fffffff, val2 = 0x7fffffff;
  for (int i = 0; i < n + 1; i++) {
    dp[i] = malloc((k + 1) * sizeof(int));
  }

  // dp base
  dp[0][0] = 0;
  for (int i = 0; i < n + 1; i++) {
    dp[i][0] = 0;
    dp[i][1] = i;
  }
  for (int i = 0; i < k + 1; i++) {
    dp[0][i] = i;
    dp[1][i] = 1;
    if (n > 1)
      dp[2][i] = 2;
  }

  if (n < 3) {
    return dp[n][k];
  }
  if (k < 2) {
    return dp[n][k];
  }

  int lo = 1, hi = 0;
  for (int i = 3; i < n + 1; i++) {
    for (int j = 2; j < k + 1; j++) {
      // dp[mid - 1][j - 1] means egg is breaking,
      // find result in mid - 1 floor with j - 1 eggs.
      // dp[i - mid][j] means egg is not breaking,
      // find result in i - mid floor with  j eggs.
      lo = 1;
      hi = i;
      while (lo + 1 < hi) {
        mid = (lo + hi) / 2;
        if (dp[mid - lo][j - 1] > dp[hi - mid][j]) {
          hi = mid;
        } else if (dp[mid - lo][j - 1] == dp[hi - mid][j]) {
          hi = lo = mid;
          break;
        } else {
          lo = mid;
        }
      }
      val1 = (dp[lo - 1][j - 1]) > (dp[i - lo][j]) ? (dp[lo - 1][j - 1] + 1)
                                                   : (dp[i - lo][j] + 1);
      val2 = (dp[hi - 1][j - 1]) > (dp[i - hi][j]) ? (dp[hi - 1][j - 1] + 1)
                                                   : (dp[i - hi][j] + 1);
      dp[i][j] = val1 < val2 ? val1 : val2;
    }
  }

  return dp[n][k];
}

int main() {
  int n, k;
  scanf("%d %d", &k, &n);

  printf("superEggDrop: %d\n", superEggDrop_kn(k, n));
  return 0;
}
