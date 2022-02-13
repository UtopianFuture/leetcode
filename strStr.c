#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int strStr_nm(char *haystack, char *needle) {
  int size1 = 0, size2 = 0;
  while (haystack[size1])
    size1++;
  while (needle[size2])
    size2++;

  if (size2 == 0)
    return 0;

  for (int i = 0; i < size1; i++) {
    if (haystack[i] == needle[0]) {
      for (int j = 0; j < size2; j++) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
        if (j == size2 - 1)
          return i;
      }
    }
  }

  return -1;
}

int kmp(char *haystack, char *needle) {
  int size1 = 0, size2 = 0;
  while (haystack[size1])
    size1++;
  while (needle[size2])
    size2++;

  if (size2 == 0)
    return 0;

  int next[size2];
  next[0] = 0;
  for (int i = 0, j = 0; i < size2; i++) {
    while (j > 0 && needle[i] != needle[j]) {
      j = next[j - 1];
    }
    if (next[i] == next[j]) {
      j++;
    }
    next[i] = j;
  }

  for (int i = 0, j = 0; i < size1; i++) {
    while (j > 0 && haystack[i] != needle[j]) {
      j = next[j - 1];
    }
    if (haystack[i] == needle[j]) {
      j++;
    }
    if (j == size2) {
      return i - j + 1;
    }
  }
  return -1;
}

int strStr_kmp(char *haystack, char *needle) {
  int size1 = 0, size2 = 0;
  while (haystack[size1])
    size1++;
  while (needle[size2])
    size2++;

  if (size2 == 0)
    return 0;

  int pi[size2];
  pi[0] = 0;
  for (int i = 1, j = 0; i < size2; i++) {
    while (j > 0 && needle[i] != needle[j]) {
      j = pi[j - 1];
    }
    if (needle[i] == needle[j]) {
      j++;
    }
    pi[i] = j;
  }

  for (int i = 0, j = 0; i < size1; i++) {
    while (j > 0 && haystack[i] != needle[j]) {
      j = pi[j - 1];
    }
    if (haystack[i] == needle[j]) {
      j++;
    }
    if (j == size2) {
      return i - size2 + 1;
    }
  }

  return -1;
}

int main() {
  char *haystack, *neelle;
  int size1, size2;
  scanf("%d\n%d\n", &size1, &size2);

  haystack = malloc(size1 * sizeof(char));
  neelle = malloc(size2 * sizeof(char));

  for (int i = 0; i < size1; i++) {
    scanf("%c", &haystack[i]);
  }
  scanf("\n");
  for (int i = 0; i < size2; i++) {
    scanf("%c", &neelle[i]);
  }

  printf("%d\n", strStr_kmp(haystack, neelle));
  // printf("%d\n", kmp(haystack, neelle));
  return 0;
}
