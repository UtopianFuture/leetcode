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

7. minimumDeleteSum  
 思路和上一题基本一致，有几个关键点:  
 - dp 数组是二维的，
 - dp base 是 `val[0][i] = val[0][i - 1] + s2[i - 1];`
 - 状态转移方程为 `min = {(val[i - 1][j] + s1[i - 1]), (val[i][j - 1] + s2[j - 1])}`
 - dp 数组一定要先初始化再使用，不然会出现在本地机器上正常执行而 leetcode 的编译器上返回未初始化的值，  
   这应该是编译器的问题，本地的编译器将这个隐藏的 bug 优化了。

8. [superEggDrop](https://leetcode-cn.com/problems/super-egg-drop/)  
  在使用二分查找优化时遇到困难，我想不用递归的方式优化，但是无法实现。  
  `superEggDrop_nn` 的思路是这样的，dp 数组表示 i 层楼 j 个鸡蛋需要测几次，所以有 kn 中情况，  
  然后要测出每种情况在最坏情况下需要测几次需要遍历 i - 1 层楼，找出最好的情况。  
  举个例子，当 `k = 2, n = 9` 时，我们在 5 楼测一次，那么 `dp[2][9] = dp[1][4] + 1 ? dp[2][4] + 1`，  
  但是这种方法的时间复杂度为 kn^2。  
  ![](https://github.com/UtopianFuture/leetcode/blob/main/image/superEggDrop_1.jpg)
  `superEggDrop_kn` 的思路时这样的，题目的要求为 k  个鸡蛋，n 层楼，最坏情况下最少的测试次数 m，  
  我们可以转换成 k 个鸡蛋，测试 m 次，最坏情况下最多能测试 n 层楼，即 `dp[i][j]` 表示 n 层楼，当 `dp[i][i] == n` 时的 m 即为所求。  
  dp base 为 `dp[1][i] = 1;`，  
  状态转换方程为  
  ```dp[i][j] = 1 + dp[i - 1][j - 1] + dp[i - 1][j];```  
  i 表示测试次数，j 表示鸡蛋数。  
  ![](https://github.com/UtopianFuture/leetcode/blob/main/image/superEggDrop_2.jpg)

9. [longestPalindromeSubseq](https://leetcode-cn.com/problems/longest-palindromic-subsequence)  
  这题的思路是这样的：dp[i][j] 表示 s[i ~ j] 子序列的最长回文子序列，对于任一个子序列的 s[i], s[j] 都有两种情况：  
  - s[i] = s[j]  
    那么 s[i] s[j] 就可以加入到最长回文子序列中  
    ```dp[i][j] = dp[i + 1][j - 1] + 2;```  
  - s[i] != s[j]
  - 那 s[i], s[j] 就不能作为最长回文子序列首尾  
    ```dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1];```

10. [stoneGame](https://leetcode-cn.com/problems/stone-game)  
  这题的思路和上一题一致。`dp[i][j]` 表示 `piles[i ~ j]` 石子堆中最大差值，dp base 是 `dp[i][i] = piles[i]`，要求的是 `dp[0][size]`，  
  而状态转移方程为: ```dp[i][j] = max{piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]}```。  
  总结一下这两题，虽然给出的都是一个序列，但是 dp 数组都是二维的，因为需要遍历这个序列中每个字符的每种组合。  
  然后关于状态转移方程，应该先考虑将问题分为子问题，如这题分成 `piles[i ~ j]` 子序列，上题也是分成 `s[i ~ j]` 子序列。  
  分成子问题之后再考虑怎样转移，那么就要确定最终要求什么，如上题要求最长回文子序列的长度，那么子问题就也是求长度，  
  加上新的字符长度会怎样变化，这题需要将胜负转换成差值，然后求差值的变化。  

11. [eraseOverlapIntervals](https://leetcode-cn.com/problems/non-overlapping-intervals/)  
  首先这题的代码在 leetcode 上能通过，但是在本地编译错误，应该是使用的 `qsort` 不同。  
  这题是区间调度的题目，思路和之前的动态规划有很大不同，将它归为单纯的贪心比较合适。  
  将 intervals 按 end 递增序排列，不重叠要满足条件 `intervals[i][0] >= base[1]` ，即 `end >= start`，  
  将不满足条件的 `intervals[i]` 去掉即可。  

12. [findMinArrowShots](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/)  
  这题和上一题一样。  

### reference
[1] https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E9%AB%98%E6%A5%BC%E6%89%94%E9%B8%A1%E8%9B%8B%E8%BF%9B%E9%98%B6.md
