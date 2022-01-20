#include "stdio.h"
#include "stdlib.h"

int mincostTickets(int *days, int daysSize, int *costs, int costsSize) {
  int *dp = malloc((days[daysSize - 1] + 1) * sizeof(int));
  int tickets[3] = {1, 7, 30};
  int val1 = 0x7fffffff;
  int val2 = 0x7fffffff;
  int min = 0x7fffffff;
  for (int i = 0; i < days[daysSize - 1] + 1; i++) {
    dp[i] = 0;
  }

  for (int i = 0; i < daysSize; i++) {
    dp[days[i]] = costs[0] * days[daysSize - 1];
  }

  for (int i = 1; i < days[daysSize - 1] + 1; i++) {
    if (dp[i] != 0) {
      for (int j = 0; j < costsSize; j++) {
        if (i - tickets[j] < 0) {
          val1 = costs[j];
        } else {
          val2 = costs[j] + dp[i - tickets[j]];
        }
        min = val2 < val1 ? val2 : val1;
        dp[i] = dp[i] < min ? dp[i] : min;
        val1 = 0x7fffffff;
        val2 = 0x7fffffff;
      }
    } else {
      dp[i] = dp[i - 1];
    }
  }

  return dp[days[daysSize - 1]] != costs[0] * days[daysSize - 1]
             ? dp[days[daysSize - 1]]
             : -1;
}

int main() {
  int daysSize = 0;
  scanf("%d", &daysSize);
  int *days = malloc(daysSize * sizeof(int));
  for (int i = 0; i < daysSize; i++) {
    scanf("%d", &days[i]);
  }

  int *costs = malloc(3 * sizeof(int));
  for (int i = 0; i < 3; i++) {
    scanf("%d", &costs[i]);
  }

  printf("costs: %d\n", mincostTickets(days, daysSize, costs, 3));

  return 0;
}
