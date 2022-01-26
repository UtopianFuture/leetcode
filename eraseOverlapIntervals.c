#include "stdio.h"
#include "stdlib.h"

int cmp(const void *_a, const void *_b) {
  int *a = *(int **)_a, *b = *(int **)_b;
  return a[0] < b[0] ? -1 : 1;
}

int eraseOverlapIntervals(int **intervals, int intervalsSize,
                          int *intervalsColSize) {
  int *base;
  int count = 1;
  if (intervalsSize == 0) {
    return 0;
  }

  qsort(intervals, intervalsSize, sizeof(int *), cmp);
  base = intervals[0];
  for (int i = 1; i < intervalsSize; i++){
    if(intervals[i][0] >= base[1]){
      count++;
      base = intervals[i];
    }
  }

  return intervalsSize - count;
}

int main() {
  int intervalsSize;
  scanf("%d", &intervalsSize);

  int **intervals;
  intervals = malloc(intervalsSize * sizeof(int *));
  for (int i = 0; i < intervalsSize; i++) {
    intervals[i] = malloc(sizeof(int));
    for (int j = 0; j < 2; j++) {
      scanf("%d", &intervals[i][j]);
    }
  }

  printf("%d\n", eraseOverlapIntervals(intervals, intervalsSize, NULL));
  return 0;
}
