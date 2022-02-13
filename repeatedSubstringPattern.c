#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

bool repeatedSubstringPattern(char *s) {
  int size = 0;
  while (s[size])
    size++;

  char *txt = malloc(2 * size * sizeof(char));
  for (int i = size; i < 2 * size; i++) {
    txt[i - size] = s[i - size];
    txt[i] = s[i - size];
  }

  int pi[size];
  pi[0] = 0;
  for (int i = 1, j = 0; i < size; i++) {
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pi[i] = j;
  }

  for (int i = 1, j = 0; i < 2 * size - 1; i++) {
    while (j > 0 && txt[i] != s[j]) {
      j = pi[j - 1];
    }
    if (txt[i] == s[j]) {
      j++;
    }
    if (j == size)
      return true;
  }
  return false;
}

int main() {
  int size = 10001;
  char *s = malloc(size * sizeof(char));
  scanf("%s", s);

  if (repeatedSubstringPattern(s))
    printf("true\n");
  else
    printf("false\n");
  return 0;
}
