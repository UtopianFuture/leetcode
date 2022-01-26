#include "stdio.h"
#include "stdlib.h"

int cmp(const void *_a, const void *_b) {
  int *a = *(int **)_a, *b = *(int **)_b;
  return a[1] < b[1] ? -1 : 1;
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize) {
  int *base;
  int count = 1;
  if (points == 0) {
    return 0;
  }

  qsort(points, pointsSize, sizeof(int *), cmp);
  base = points[0];
  for (int i = 1; i < pointsSize; i++) {
    if (points[i][0] > base[1]) {
      count++;
      base = points[i];
    }
  }

  return count;
}

int main() {
  int pointsSize;
  scanf("%d", &pointsSize);

  int **points;
  points = malloc(pointsSize * sizeof(int *));
  for (int i = 0; i < pointsSize; i++) {
    points[i] = malloc(sizeof(int));
    for (int j = 0; j < 2; j++) {
      scanf("%d", &points[i][j]);
    }
  }

  printf("%d\n", findMinArrowShots(points, pointsSize, NULL));
  return 0;
}
