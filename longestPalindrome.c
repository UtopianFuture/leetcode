#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// char *longestPalindrome(char *s) {
//   int max = 1, low = 0, high = 0;
//   int size = 0;
//   while (s[size])
//     size++;
//
//   int dp[size][size];
//   memset(dp, 0, sizeof(dp));
//   for (int i = 0; i < size; i++) {
//     dp[i][i] = 1;
//   }
//
//   for (int i = size - 2; i >= 0; i--) {
//     for (int j = i + 1; j < size; j++) {
//       if (s[i] == s[j] &&
//           ((dp[i + 1][j] >= j - i - 1) || (dp[i][j - 1] >= j - i - 1)) &&
//           dp[i + 1][j] == dp[i][j - 1]) {
//         if (i == j - 1) { // 'aa'
//           dp[i][j] =
//               dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] + 1 : dp[i][j - 1] +
//               1;
//         } else { // 'aba'
//           dp[i][j] =
//               dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] + 2 : dp[i][j - 1] +
//               2;
//         }
//       } else {
//         dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1];
//       }
//       if (dp[i][j] > max) {
//         low = i;
//         high = j;
//         max = dp[i][j];
//       }
//     }
//   }
//
//   int res_size = 0;
//   char *res = malloc((high - low + 1 + 1) * sizeof(char));
//   for (int i = low; i <= high; i++) {
//     res[res_size++] = s[i];
//   }
//   res[res_size] = 0;
//
//   return res;
// }

char *longestPalindrome(char *s) {
  int max = 1, low = 0;
  int size = 0;
  while (s[size])
    size++;

  int dp[size][size];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < size; i++) {
    dp[i][i] = 1;
  }

  for (int l = 2; l <= size; l++) {
    for (int i = 0; i < size; i++) {
      int j = i + l - 1;
      if (j >= size) {
        break;
      }

      if (s[i] != s[j]) {
        dp[i][j] = 0;
      } else {
        if (j - i < 3) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = dp[i + 1][j - 1];
        }
      }

      if (dp[i][j] && j - i + 1 > max) {
        max = j - i + 1;
        low = i;
      }
    }
  }

  int res_size = 0;
  char *res = malloc((max + 1) * sizeof(char));
  for (int i = 0; i < max; i++) {
    res[res_size++] = s[i + low];
  }
  res[res_size] = 0;

  return res;
}
int main() {
  char *s = malloc(1000 * sizeof(char));
  scanf("%s", s);

  printf("%s\n", longestPalindrome(s));
  return 0;
}
