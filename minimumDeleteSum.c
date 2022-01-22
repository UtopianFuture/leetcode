#include "stdio.h"
#include "stdlib.h"

int minimumDeleteSum(char *s1, char *s2) {
  int size1 = 0, size2 = 0;
  while (s1[size1])
    size1++;
  while (s2[size2])
    size2++;

  int **val = malloc((size1 + 1) * sizeof(int *));
  for (int i = 0; i < size1 + 1; i++) {
    val[i] = malloc((size2 + 1) * sizeof(int));
  }

  val[0][0] = 0;
  for (int i = 1; i < size2 + 1; i++) {
    val[0][i] = val[0][i - 1] + s2[i - 1];
  }
  for (int i = 1; i < size1 + 1; i++) {
    val[i][0] = val[i - 1][0] + s1[i - 1];
  }

  for (int i = 1; i < size1 + 1; i++) {
    for (int j = 1; j < size2 + 1; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        val[i][j] = val[i - 1][j - 1];
      } else {
        val[i][j] = (val[i - 1][j] + s1[i - 1]) < (val[i][j - 1] + s2[j - 1])
                        ? (val[i - 1][j] + s1[i - 1])
                        : (val[i][j - 1] + s2[j - 1]);
      }
    }
  }
  
  return val[size1][size2];
}

int main() {
  char *s1 = malloc(500 * sizeof(char)), *s2 = malloc(500 * sizeof(char));
  scanf("%s", s1);
  scanf("%s", s2);

  printf("minimumDeleteSum: %d\n", minimumDeleteSum(s1, s2));
  return 0;
}
