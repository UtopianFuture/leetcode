# leetcode
this is leetcode exercise.
1. fib
  easy, nothing important.

2. coinChange
  最重要的是理解 'dp'，'dp' 是一个数组，长度为 amount + 1(0 ~ amount)，每个元素表示该 amount 最少的分配方式，
  除 dp[0] = 0 外，其他的元素都初始化为 amount + 1，即默认是没有正确的分配方式。
  另一个关键是理解 amount 的最少分配方式是 amount - coins[i] 的最少分配方式加1。
  ```dp[i] = (dp[i] < (dp[i - coins[j]] + 1)) ? dp[i] : (dp[i - coins[j]] + 1);```

3. climbStairs
  same as fib

4. mincostTickets
  这题大体上和 `coinchange` 差不多，但有一点需要注意，由于天数不是连续的，所有没有去旅游的那天 cost 和前一天一样。
  ```
  if (dp[i] != 0) {
    
    ...

     } else {
      dp[i] = dp[i - 1];
    }
  ```
5. lengthOfLIS
 思路和 `coinchange` 一样，即：最长递增子序列等于前面的比自己小的元素中的最长递增子序列加1。

6. minDistance
  还是动态规划，思路是最短距离等于上 word1[size1] ~ word2[size2 - 1] 的最短距离加1。但这题的 dp 是二维数组，
  dp[i][j] 表示 word1[i] 到 word2[j] 的最短距离。
  然后关于增，删和替换操作体现在 dp 上就是:
  ```
    x h o r s e
  x 0 1 2 3 4 5
  r 1
  o 2
  s 3
  ```
  当 `i = 1, j = 1` 时  
  `dp[i - 1][j]; // 删除 h `  
  `dp[i][j - 1]; // 在 r 前面增加 h`  
  `dp[i - 1][j - 1]; // 替换`  
