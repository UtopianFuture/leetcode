#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// out of time limited
// bool dp(char *s, int i, int sizes, char *p, int j, int sizep) {
//   if (j == sizep) {
//     return i == sizes;
//   }
//   if (i == sizes) {
//     if (j == sizep) {
//       return true;
//     } else if (j != sizep) {
//       for (int k = j; k < sizep; k++) {
//         if (p[k] != '*') {
//           return false;
//         }
//       }
//       return true;
//     } else {
//       return false;
//     }
//   }
//
//   bool res = false;
//   // match
//   if (s[i] == p[j] || p[j] == '?') {
//     // normal match
//     res = dp(s, i + 1, sizes, p, j + 1, sizep);
//   } else if (p[j] == '*') {
//     // 'j + 1' match 0 time, 'i + 1' match 1 time
//     res = dp(s, i, sizes, p, j + 1, sizep) || dp(s, i + 1, sizes, p, j,
//     sizep);
//   } else { // don't match
//     res = false;
//   }
//   return res;
// }
//
// bool isMatch(char *s, char *p) {
//   int sizes = 0, sizep = 0;
//   while (s[sizes])
//     sizes++;
//   while (p[sizep])
//     sizep++;
//
//   return dp(s, 0, sizes, p, 0, sizep);
// }

bool isMatch(char *s, char *p) {
  int sizes = 0, sizep = 0;
  while (s[sizes])
    sizes++;
  while (p[sizep])
    sizep++;

  int dp[sizep + 1][sizes + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= sizep; i++) {
    if (p[i - 1] == '*') {
      dp[i][0] = 1;
    } else {
      break;
    }
  }

  for (int i = 1; i <= sizep; i++) {
    for (int j = 1; j <= sizes; j++) {
      if (s[j - 1] == p[i - 1] || p[i - 1] == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      } else if (p[i - 1] == '*') {
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      } else {
        dp[i][j] = 0;
      }
    }
  }

  return dp[sizep][sizes];
}

int main() {
  char *s = malloc(100 * sizeof(char));
  scanf("%s", s);

  char *p = malloc(30 * sizeof(char));
  scanf("%s", p);

  if (isMatch(s, p)) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}
