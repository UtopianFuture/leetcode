#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

bool dp(char *s, int i, char *p, int j) {
  int sizes = 0, sizep = 0;
  while (s[sizes])
    sizes++;
  while (p[sizep])
    sizep++;

  if (j == sizep) {
    return i == sizes;
  }
  if (i == sizes) {
    // isn't *x*x*z module
    if ((sizep - j) % 2 == 1) {
      return false;
    }
    for (; j + 1 < sizep; j += 2) {
      if (p[j + 1] != '*') {
        return false;
      }
    }
    return true;
  }

  bool res = false;
  // match
  if (s[i] == p[j] || p[j] == '.') {
    if (p[j + 1] == '*') {
      // "j + 2" - '*' match 0 time, "i + 1" - '*' match 1 time
      // dp(s, i + 1, p, j) can match many times
      res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
    } else {
      // normal match
      res = dp(s, i + 1, p, j + 1);
    }
  } else { // don't match
    if (p[j + 1] == '*') {
      // s[i] != p[j], '*' match 0 time
      res = dp(s, i, p, j + 2);
    } else {
      res = false;
    }
  }
  return res;
}

bool isMatch(char *s, char *p) { return dp(s, 0, p, 0); }

// bool isMatch(char *s, char *p) {
//   int sizes = 0, sizep = 0;
//   while (s[sizes])
//     sizes++;
//   while (p[sizep])
//     sizep++;
//
//   int next[sizes];
//   next[0] = 0;
//   for (int i = 1, j = 0; i < sizes; i++) {
//     if (j > 0 && s[i] != s[j]) {
//       j = next[j - 1];
//     }
//     if (s[i] == s[j]) {
//       j++;
//     }
//     next[i] = j;
//   }
//
//   for (int i = 0, j = 0; i < sizep; i++) {
//     if (p[i + 1] == '*' && p[i] != s[j] && p[i] != '.') {
//       i++;
//       continue;
//     }
//     while (j > 0 && p[i] != s[j] && !(p[i] == '.') &&
//            !(p[i] == '*' && (p[i - 1] == s[j] || p[i - 1] == '.'))) {
//       j = next[j - 1];
//     }
//     if ((p[i] == '*' && (p[i - 1] == s[j] || p[i - 1] == '.')) ||
//         p[i] == s[j] || p[i] == '.') {
//       j++;
//     }
//     if (j == sizes) {
//       if (i == sizep - 1)
//         return true;
//       else
//         return false;
//     }
//   }
//   return false;
// }

// bool isMatch(char *s, char *p) {
//   int sizes = 0, sizep = 0;
//   while (s[sizes])
//     sizes++;
//   while (p[sizep])
//     sizep++;
// 
//   int dp[sizep + 1][sizes + 1];
//   memset(dp, 0, sizeof(dp));
//   dp[0][0] = 1;
//   for (int i = 2; i <= sizep; i += 2) {
//     if (p[i - 1] == '*') {
//       dp[i][0] = 1;
//     } else {
//       break;
//     }
//   }
// 
//   for (int i = 1; i <= sizep; i++) {
//     for (int j = 1; j <= sizes; j++) {
//       if (s[j - 1] == p[i - 1] || p[i - 1] == '.') {
//         dp[i][j] = dp[i - 1][j - 1];
//       } else if (p[i - 1] == '*') {
//         if (p[i - 2] != s[j - 1] && !(p[i - 2] == '.')) {
//           dp[i][j] = dp[i - 2][j];
//         } else {
//           for (int k = 0; k <= j; k++){
//             dp[i][j] |= dp[i- 1][k];
//           }
//           // dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1];
//         }
//       } else {
//         dp[i][j] = 0;
//       }
//     }
//   }
//   return dp[sizep][sizes];
// }

int main() {
  char *s = malloc(20 * sizeof(char));
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
