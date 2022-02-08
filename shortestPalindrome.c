#include "stdio.h"
#include "stdlib.h"

char *shortestPalindrome(char *s) {
  int size1 = 0;
  while (s[size1])
    size1++;

  char *txt = malloc(2 * size1 * sizeof(char));
  for (int i = 0; i < size1; i++) {
    txt[i] = s[size1 - 1 - i];
  }

  int next[size1];
  next[0] = 0;
  for (int i = 1, j = 0; i < size1; i++) {
    while (j > 0 && s[i] != s[j]) {
      j = next[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    next[i] = j;
  }

  int j = 0;
  for (int i = 0; i < size1; i++) {
    while (j > 0 && s[j] != txt[i]) {
      j = next[j - 1];
    }
    if (s[j] == txt[i]) {
      j++;
    }
    if (i == size1 - 1) {
      break;
    }
  }

  int size2 = size1;
  while (j < size1) {
    txt[size2++] = s[j++];
  }
  for (int i = size2; i < size1 * 2; i++){
    txt[i] = 0;
  }

  return txt;
}

int main() {
  int size;
  scanf("%d\n", &size);

  char *s = malloc(size * sizeof(char));
  for (int i = 0; i < size; i++) {
    scanf("%c", &s[i]);
  }

  printf("%s\n", shortestPalindrome(s));
  return 0;
}
