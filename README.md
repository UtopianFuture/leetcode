# leetcode
this is leetcode exercise.
1. [fib](https://leetcode-cn.com/problems/fibonacci-number/)  
  这题动态规划解法和递归解法的区别是消除重复子问题。

2. [coinChange](https://leetcode-cn.com/problems/coin-change/)  
  最重要的是理解 'dp'，'dp' 是一个数组，长度为 amount + 1(0 ~ amount)，  
  每个元素表示该 amount 最少的分配方式，除 dp[0] = 0 外，  
  其他的元素都初始化为 amount + 1，即默认是没有正确的分配方式。  
  另一个关键是理解 amount 的最少分配方式是 amount - coins[i] 的最少分配方式加1。  
    ```c
    dp[i] = (dp[i] < (dp[i - coins[j]] + 1)) ? dp[i] : (dp[i - coins[j]] + 1);
    ```

3. [climbStairs](https://leetcode-cn.com/problems/climbing-stairs/)  
  最后一次可能是跨一步或两步，即：
  ```c
  dp[i] = dp[i - 1] + dp[i - 2];
  ```

4. [mincostTickets](https://leetcode-cn.com/problems/minimum-cost-for-tickets/)  
  这题大体上和 `coinchange` 一样，但有一点需要注意，由于天数不是连续的，  
  所有没有去旅游的那天 cost 和前一天一样。  
    ```c
    if (dp[i] != 0) {
      dp[i] = dp[i] < dp[i - tickets[j]] + 1 ? dp[i] : dp[i - tickets[j]] + 1;
    } else {
      dp[i] = dp[i - 1];
    }
    ```

5. [lengthOfLIS](https://leetcode-cn.com/problems/longest-increasing-subsequence/)  
  LIS: 最长递增自序列  
  思路和 `coinchange` 一样，即：LIS 等于前面的比自己小的元素中的 LIS 加1。  

6. [minDistance](https://leetcode-cn.com/problems/edit-distance/)  
  还是动态规划，思路是最短距离等于上 word1[size1] ~ word2[size2 - 1] 的最短距离加1。  
  但这题的 dp 是二维数组，dp[i][j] 表示 word1[i] 到 word2[j] 的最短距离。  
  然后关于增，删和替换操作体现在 dp 上就是:  
    ```c
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

7. [minimumDeleteSum](https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/)  
 思路和上一题基本一致，有几个关键点:  
 - dp 数组是二维的，
 - dp base 是 `val[0][i] = val[0][i - 1] + s2[i - 1];`
 - 状态转移方程为 `min = {(val[i - 1][j] + s1[i - 1]), (val[i][j - 1] + s2[j - 1])}`
 - dp 数组一定要先初始化再使用，不然会出现在本地机器上正常执行而 leetcode 的编译器上返回未初始化的值，  
   这应该是编译器的问题，本地的编译器将这个隐藏的 bug 优化了。

8. [superEggDrop](https://leetcode-cn.com/problems/super-egg-drop/)  
  在使用二分查找优化时遇到困难，我想不用递归的方式优化，但是无法实现。  
  `superEggDrop_nn` 的思路是这样的，dp 数组表示 i 层楼 j 个鸡蛋需要测几次，  
  所以有 kn 种情况，然后要测出每种情况在最坏情况下需要测几次需要遍历 i - 1 层楼，  
  找出最好的情况。举个例子，当 `k = 2, n = 9` 时，我们在 5 楼测一次，  
  那么 `dp[2][9] = dp[1][4] + 1 ? dp[2][4] + 1`，  
  但是这种方法的时间复杂度为 kn^2。  
  ![](https://github.com/UtopianFuture/leetcode/blob/main/image/superEggDrop_1.jpg)
  `superEggDrop_kn` 的思路时这样的，题目的要求为 k 个鸡蛋，n 层楼，最坏情况下最少的测试次数 m，  
  我们可以转换成 k 个鸡蛋，测试 m 次，最坏情况下最多能测试 n 层楼，即 `dp[i][j]` 表示 n 层楼，当 `dp[i][i] == n` 时的 m 即为所求。  
  dp base 为 `dp[1][i] = 1;`，  
  状态转换方程为  
  ```c
  dp[i][j] = 1 + dp[i - 1][j - 1] + dp[i - 1][j];
  ```
  i 表示测试次数，j 表示鸡蛋数。  
  ![](https://github.com/UtopianFuture/leetcode/blob/main/image/superEggDrop_2.jpg)

9. [longestPalindromeSubseq](https://leetcode-cn.com/problems/longest-palindromic-subsequence)  
  这题的思路是这样的：dp[i][j] 表示 s[i ~ j] 子序列的最长回文子序列，对于任一个子序列的 s[i], s[j] 都有两种情况：  
  - s[i] = s[j]  
    那么 s[i] s[j] 就可以加入到最长回文子序列中  
    ```c
    dp[i][j] = dp[i + 1][j - 1] + 2;
    ```
  - s[i] != s[j]
  - 那 s[i], s[j] 就不能作为最长回文子序列首尾  
      ```c
      dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1];
      ```

10. [stoneGame](https://leetcode-cn.com/problems/stone-game)  
  `dp[i][j]` 表示 `piles[i ~ j]` 石子堆中当前玩家与另一个玩家的石子数量差的最大值，  
  dp base 是 `dp[i][i] = piles[i]`，要求的是 `dp[0][size]`，  
  当 `i < j` 时，当前玩家可以选择取走 `piles[i]` 或 `piles[j]`，  
  然后轮到另一个玩家在剩下的石子堆中取走石子。在两种方案中，当前玩家会选择最优的方案，  
  使得自己的石子数量最大化。而状态转移方程为:  
  ```c
  dp[i][j] = max{piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]}
  ```
  官方解析中给出了数学分析，这种情况永远是先手获胜，所以可以直接返回 true。  
  总结一下这题和上一题，虽然给出的都是一个序列，但是，虽然给出的都是一个序列，但是 dp 数组都是二维的，因为需要遍历这个序列中每个字符的每种组合。  
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

13. [strStr](https://leetcode-cn.com/problems/implement-strstr/)  
  这题用暴力解法法超时，需要使用 kmp 算法。使用 kmp 算法解决字符匹配类问题的关键就是 pat 字符串的 kmp 数组。  
  然后根据 kmp 数组求解。  
  每个字符串对应的 kmp 数组是确定的，可以用这个算法来求:  
    ```c
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
    ```
  然后确定 pat 字符串是否在 txt 字符串中出现过，可以使用这个算法:  
    ```c
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
    ```

14. [repeatedSubstringPattern](https://leetcode-cn.com/problems/repeated-substring-pattern/)  
  这题也是用 kmp 算法，但是比较巧妙，给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。  
  将这个字符串重复两次，变成 `s[0 ~ 2 * size - 1]`， 如果这个字符串可以由它的一个子串重复多次构成，  
  那么在 `s[1 ~ 2 * size -2]` 中一定存在该子串。  

15. [shortestPalindrome](https://leetcode-cn.com/problems/shortest-palindrome/)  
  这题的做法很巧妙，求最短回文串，用暴力的解法比较简单，将后面的字符和前面的字符一个个遍历对比,    
  如果不相同，则插入。  
  而 KMP 算法是先求出原字符串的 next 数组，然后将字符串反转得到 txt 数组。之后按照 kmp 遍历，  
  看 txt 数组的最后一个字符对应 next 数组的哪个字符，将该字符之后的字符都加入到 txt 数组。  

16. [longestPalindrome](https://leetcode-cn.com/problems/longest-palindromic-substring/)  
  - 原做法（错误）
  这题没有使用 kmp 算法，而是使用动态规划，`dp[i][j]` 表示 `s[i ~ j]` 的最长回文串，  
  注意这里还需要考虑一个事情  
    ```c
    if (s[i] == s[j] && ((dp[i + 1][j] >= j - i - 1) || (dp[i][j - 1] >= j - i - 1)))
    ```
  即当 `s[i] == s[j]` 时还要看 `s[i + 1 ~ j]` 和 `s[i ~ j - 1]` 是否是回文串。  
  如果不考虑会出现这种情况: `asdfa` 最后一个字符和第一个字符相等，但是中间的三个字符不是回文串，所以不能直接加2。  
  - 新做法
  不要想的那么复杂，考虑两点:  
  （1）遍历每一个子串，  
  （2）动态转移方程  
  动态转移方程是这样的:  
  （1）dp 数组表示 `s[i] ~ s[j]` 是否是回文串；  
  （1）如果该子串 `s[i] != s[j]`， 那么这个子串肯定不是回文；  
  （2）如果 `s[i] == s[j]`，那么该子串是否是回文跟 `s[i + 1] ~ s[j - 1]` 相同。  
  这题和[最长回文子序列](#9. [longestPalindromeSubseq](https://leetcode-cn.com/problems/longest-palindromic-subsequence))  
  需要分清楚，一个是子序列，可以不连续，dp 数组表示的是 `s[i ~ j]` 子串中的最长回文子序列长度，  
  而这题 dp 数组表示的 `s[i ~ j]` 是否是回文子串。动态转移方程是是类似的。  
  
  还有一点需要注意，由于使用了 `-fsanitize=address` 来进行边界检查，所以在创建 `char *` 时要这样  
    ```c
    char *res = malloc((max + 1) * sizeof(char));
     for (int i = 0; i < max; i++) {
       res[res_size++] = s[i + low];
     }
     res[res_size] = 0;
    ```
  即数组大小比需要的大 1，然后最后一个 byte 设为 0。  

17. [maxProfit](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)  
  股票问题：
  这种问题有3个状态，天数，允许交易的最大次数和当前是否持有股票。利用三维 dp 数组可以表示所以的状态：  
    ```c
    dp[i][k][0 or 1]
    0 <= i <= n - 1, 1 <= k <= K
    n 为天数，大 K 为交易数的上限，0 和 1 代表是否持有股票。
    此问题共 n × K × 2 种状态，全部穷举就能搞定。
  
    for 0 <= i < n:
      for 1 <= k <= K:
          for s in {0, 1}:
              dp[i][k][s] = max(buy, sell, rest)
    ```
  然后最后要求的就是 `dp[n - 1][K][0]`  
  那么状态转移方程是这样的：  
    ```c
    // 今天没有持有股票，可能是保持昨天的状态，也可能是昨天持有股票，但是今天卖了
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    // 今天持有股票，可能是保持昨天的状态，也可能是今天买入股票，那么最大交易次数就减 1。
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
    ```

18. [maxProfit_ii](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)  
  dp base 还是和上题一样  
    ```c
    int dp_0 = 0, dp_1 = 0x80000001;
    ```
  状态转移方程也是一样的，  
    ```c
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
    ``` 
  但是 k 是无限的，`[k]` 和 `[k - 1]` 一样，可以约掉，  
  得到如下状态转移方程，
    ```c
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])
    ```
  那么 k 成为无关状态，  
    ```c
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
    ```
  再将 `dp[i][0]` 化简为 `dp_0`，这里有一点需要注意，`dp[i][0]` 表示的是上一天的利润，  
  换成 `dp_0` 后  
    ```c
    dp_0 = max(dp_0, dp_1 + prices[i]);
    dp_1 = max(dp_1, dp_0 - prices[i]);
    ```
  `dp_0` 已经经过计算，变成今天的利润，所以要利用一个 temp 来记录昨天的利润。  

19. [maxProfit_iii](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)  
  这题是上一题的进一步，`k = 2`，之后类似的题目都是套这种模板，  
  - dp base  
    ```c
    for (int i = 0; i < pricesSize; i++) {
      dp_0[i][0] = 0;
      dp_1[i][0] = -prices[i];
    }
    ```
  因为 i 是从 0 开始的，所有要初始化 `i - 1 == -1` 的情况，  
    ```c
    if (i - 1 == -1) {
      dp_0[i][k] = 0;
      dp_1[i][k] = -prices[i];
      continue;
    }
    ```

20. [maxProfit_iv](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)  
  `k = integer`，但是如果 `k > days / 2` 的就和 `k = inf` 一样的，  
  所以在上一题的基础加上加一个限制条件即可  
    ```c
    if (k > pricesSize / 2) {
      return maxProfit_inf(prices, pricesSize);
    }
    ```

21. [maxProfit_freeze](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)  
  这题在 18 题的基础上简单修改一下即可，冰冻期为 n 则状态转移方程变为：  
    ```c
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-n][k][0] - prices[i])
    ```
  然后一样，k 变成无关变量，可以约掉。  

22. [maxProfit_fee](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)  
  这题还是 18 题的变种，只需要在收入上减去 fee 即可。  
    ```c
    dp_0 = dp_0 > dp_1 + prices[i] - fee ? dp_0 : dp_1 + prices[i] - fee;
    ```

23. [rob](https://leetcode-cn.com/problems/house-robber/)  
  这题比较简单，用一个一维的 dp 数组表示到当前房间时最高金额。
  - dp base  
    ```c
    if(numsSize == 1){
      return nums[0];
    }
    if(numsSize == 2){
      return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    if(numsSize == 3){
      return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
    }
  
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[2] + dp[0];
    ```
  - 状态转移方程  
    ```c
    dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i]
    ```
24. [rob_ii](https://leetcode-cn.com/problems/house-robber-ii/)  
  首尾是连接的，那么就分两种情况考虑，
  （1）抢劫 first house 不抢劫 last house  
    ```c
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[2] + dp[0];
    for (int i = 3; i < numsSize - 1; i++) { // don't rob the last house
      dp[i] = dp[i - 2] > dp[i - 3] ? dp[i - 2] + nums[i] : dp[i - 3] + nums[i];
    }
    ```
  （2）抢劫 last house 不抢劫 first house  
    ```c
    dp[1] = nums[1];
    dp[2] = nums[2];
    dp[3] = nums[3] + dp[1];
    for (int i = 4; i < numsSize; i++) { // don't rob the first house
      dp[i] = 0;
      dp[i] = dp[i - 2] > dp[i - 3] ? dp[i - 2] + nums[i] : dp[i - 3] + nums[i];
    }
    ```
  返回大的那个。  

25. [rob_iii](https://leetcode-cn.com/problems/house-robber-iii/)  
  这题虽然用的也是和上题类似的动态规划思路，但由于需要遍历的是二插树，又有些不一样。  
  每个节点可能被抢也可能没被抢，定义一个结构体来表示每个节点的状态，   
    ```c
    struct status {
    int do_rob; // 该 house 被抢劫后的总金额
    int dont_rob; // 该 house 没被抢劫的总金额
    };
    ```
  遍历每个节点，  
  ```c
  struct status left = dp(node->left);
  struct status right = dp(node->right);
  ```
  而该节点的状态是这样的，  
  ```c
  // 如果该节点被抢劫，那么总金额为该节点的金额加上子结点没有被抢劫的金额
  int do_rob = node->val + left.dont_rob + right.dont_rob;
  // 如果该节点没有被抢劫，那么子结点可被抢也可不被抢，总金额为大的那个
  int dont_rob =
      (left.do_rob > left.dont_rob ? left.do_rob : left.dont_rob) +
      (right.do_rob > right.dont_rob ? right.do_rob : right.dont_rob);
  ```

26. [isMatch_regular](https://leetcode-cn.com/problems/regular-expression-matching/)  
  这题开始想错了方向，想着直接使用 kmp 字符匹配，然后对 '.', '*' 进行特殊处理即可，  
  例如：  
  ```c
  if ((p[i] == '*' && (p[i - 1] == s[j] || p[i - 1] == '.')) ||
    p[i] == s[j] || p[i] == '.') {
    j++;
  }
  ```
  但是没有抓住问题的关键，即 '*' 的匹配的次数，可以为任意次。  
  那么当 `p[i + 1] == '*'` 时，我们遍历所有的情况，即匹配 0 次或多次。  
  ```c
  if (p[j + 1] == '*') {
      // "j + 2" - '*' match 0 time, "i + 1" - '*' match 1 time
      // dp(s, i + 1, p, j) can match many times
      res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
    }
  ```
  但关键是这点想不到啊。  

27. [isMatch_wildcard](https://leetcode-cn.com/problems/wildcard-matching/)
  这题和上一题一样，只是 '*' 的意义变成匹配任意字符串，  
  那么当 `p[j] == '*'` 时还是匹配 0 个字符或多个字符。
  ```c
  if (p[j] == '*') {
    // 'j + 1' match 0 time, 'i + 1' match 1 time
    res = dp(s, i, sizes, p, j + 1, sizep) || dp(s, i + 1, sizes, p, j, sizep);
  }
  ```
  但是这个做法会超时，所以使用了参考解法，还是动态规划的思路，  
  动态转移方程：  
  ```c
  if (s[j - 1] == p[i - 1] || p[i - 1] == '?') {
    dp[i][j] = dp[i - 1][j - 1];
  } else if (p[i - 1] == '*') {
    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
  } else {
    dp[i][j] = 0;
  }
  ```
  dp base:  
  这里 dp base 比较巧妙，当两个空字符串匹配时返回 true，  
  当 `p[i] == '*'` 时返回 true。  
  ```c
  int dp[sizep + 1][sizes + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= sizep; i++) {
    if (p[i - 1] == '*') {
      dp[i][0] = 1;
    } else {
      break;
    }
  }
  ```

28. [longestCommonSubsequence](https://leetcode-cn.com/problems/longest-common-subsequence)  
  这题是比较简单的动态规划问题。看到两个字符串，条件反射的想到 dp 数组是二维的，  
  然后状态转移方程是  
  ```c
  if (text1[i - 1] == text2[j - 1]) {
    dp[i][j] = dp[i - 1][j - 1] + 1;
  } else {
    dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
  ```
  总结一下，涉及的公共子序列，子串等的题目都是用二维 dp 数组，然后在 `dp[i - 1][j]`, `dp[i][j - 1]`,  
  `dp[i - 1][j - 1]` 中找转移方程。  

29. [maxProduct](https://leetcode-cn.com/problems/maximum-product-subarray/)  
  这题和之前的动态规划有些不一样，因为它不满足“最优子结构”，  
  即当前位置的最优解未必是由前一个位置的最优解转移得到的。所以不能直接用二维 dp 数组来解决。  
  考虑题义，`nums[i]` 可正可负，可能前一个子序列的乘积是负的，但是负负得正，  
  所以动态转移方程是这样的：  
  ```c
  dp_max = max(dp_max * nums[i], dp_min * nums[i], nums[i]);
  dp_min = min(dp_max * nums[i], dp_min * nums[i], nums[i]);
  ```
  不但记录最大值，还记录最小值。  

30. [maxSubArray](https://leetcode-cn.com/problems/maximum-subarray/)  
  这题比较简单。

31. [deleteAndEarn](https://leetcode-cn.com/problems/delete-and-earn/)  
  这题和 [rob](#23. [rob](https://leetcode-cn.com/problems/house-robber/)) 类似，但要做一个转换。  
  删除所有等于 `nums[i] - 1` 和 `nums[i] + 1` 的元素就等于不抢劫相邻房子。  
  定义一个 sum 数组，  
  ```c
    for (int i = 0; i < numsSize; i++) {
    sum[nums[i]] += nums[i];
  }
  ```
  即将无序的 nums 排列成有序的房子，没有的地方初始化为 0。  

32. [LRUCache](https://leetcode-cn.com/problems/lru-cache/)  
  这题需要用到双向链表和哈希表，双向循环链表作为 cache 保存 value，  
  哈希表保存 key 与 value 在 cache 中位置的映射。  
  对于 put 操作而言，如果 key 在哈希表中存在，那么只需要改变对应的 value，  
  同时将这个 node 移到双向链表的头部；如果不存在，需要考虑 capacity 是否足够，  
  如果 `used < capacity` 那么直接在链表头部插入一个 node，并将这个 node 的地址  
  写入哈希表 key 对应的位置；否则需要将链表尾部的一个 node 删除，并创建一个 node  
  插入到链表头部。  
  对于 get 操作，如果哈希表中存在，那么将对应的 node 移到链表头部；否则返回 -1 。  
  cache 的数据结构是这样的：  
  ```c
  typedef struct {
    struct node *value_location[10001]; // hash table
    int used;
    int capacity;
    struct node *head, *tail; // list head node and tail node
  } LRUCache;
  ```
  这里哈希表还可以优化，因为解决哈希冲突太麻烦了，所以将 key 的映射关系保存在 `value_location[key]`，  
  size 就是 `max(key) + 1`。
  然后还有一个小技巧，在双向链表的实现中，使用一个伪头部（dummy head）和伪尾部（dummy tail）标记界限，  
  就是这里的 `struct node *head, *tail;` 这样在添加节点和删除节点的时候就不需要检查相邻的节点是否存在。


33. [isSameTree](https://leetcode-cn.com/problems/same-tree/)  
  用中序遍历遍历整棵树即可。  

34. [implementStack](https://leetcode-cn.com/problems/implement-stack-using-queues/)  
  这题只是为了使用 stack，直接复制官方的解答。

35. [buildTree](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)  
  根据前序遍历和中序遍历构造二叉树。  
  前序遍历的第一个节点是根节点，然后在中序遍历中定位到根节点，即可知道左子树和右子树中的节点数目。  
  这样以来，就知道了左子树的前序遍历和中序遍历结果，以及右子树的前序遍历和中序遍历结果，  
  之后递归地对构造出左子树和右子树，再将这两颗子树接到根节点的左右位置即可。

36. [deleteNode](https://leetcode-cn.com/problems/delete-node-in-a-bst/)  
  删除节点分 3 种情况：
  - 叶子节点，直接删除；
  - 有右子树，使用后继节点替代，然后在右子树中删除该后继节点；
  - 没有右子树，但有左子树，使用前驱节点替代，然后在左子树中删除该前驱节点；  

37. [insertIntoBST](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)  
  还是二叉搜索树，找到对应的空节点，将其链接到父节点即可。  

38. [isValidBST](https://leetcode-cn.com/problems/validate-binary-search-tree/)  
  因为所有的左右子树都要满足二叉搜索树，所以需要加个上下限，防止如下情况出现：  
  ```c
  5
   \
   6
  / \
  3  7
  ```
  ```
  if (root->val <= min || root->val >= max) {
    return false;
  }
  ```

39. [nextGreaterElement](https://leetcode-cn.com/problems/next-greater-element-i/)  
  这题需要使用哈希表和堆栈，用 c 语言写不方便，故用 c++ 。   
  但是核心都是一样的，  
  ```c
  for (int i = 0; i < nums2Size; i++) {
    while (!Empty(s) && Top(s) < nums2[i]) { // 栈非空，同时栈顶元素要大于当前需要比较的元素
      Pop(s);
    }
    tmp[i] = Empty(s) ? -1 : Top(s); // 后面的元素中有比该元素大的
    Push(s, nums2[i]);
  }
  ```

40. [maxSlidingWindow](https://leetcode-cn.com/problems/sliding-window-maximum/)  
  这题用了一个单调队列，这个队列中的元素是单调递增（递减）的。
  对于给定的数组，将每个元素入队，因为队列是单调的，所以如果队尾的元素小于将要入队的元素，  
  那么将队列中的元素删除，  
  ```c
  for (int i = 0; i < k; i++) {
    while (head < tail && nums[i] > nums[q[tail - 1]]) {
      tail--;
    }
    q[tail++] = i;
  }
  ```
  同时需要注意的是队列保存的是该元素的索引。  
  窗口每向后移动一次，将新加的元素入队，如果该元素最大，那么队列前面保存的元素自然就被删除了，  
  如果不够大，该元素入队之后也到不了队列头部。这样入队之后，    
  因为队列的头部始终是这个窗口的最大值，那么直接保存队列头部元素即可。  
  如果该头部已经不在该窗口范围，需要更新队列头部。  
  ```c
  while (q[head] <= i - k) {
    head++;
  }
  ```

41. [mergeTwoLists](https://leetcode-cn.com/problems/merge-two-sorted-lists/)  
  定义一个 next 指向两个链表中值较小的那个，然后将较小的那个链表表头指向下一个元素，  
  再重复进行下一个比较。  
 
42. [mergeKLists](https://leetcode-cn.com/problems/merge-k-sorted-lists/)  
  思路很简单，就是不断的两两合并，利用上一题的代码，大部分时间用在调整指针上。  
  开始只是给每个 ListNode 赋值了，但是没有将节点链接起来，所以在 `mergeTwoLists` 中  
  访问 `list2->next` 总是报空指针异常。需要注意阿。  

43. [designTwitter](https://leetcode-cn.com/problems/design-twitter/)  
  这题超时了，没有通过。先记录一下思路。  
  首先是几个关键的数据结构：
  ```c
  struct Tweet {
    int tweetId;
    int time;
    struct Tweet *next;
  };

  struct User {
    int userId;
    int followed[501];
    int follows_nums;
    struct Tweet *head;
  };

  typedef struct {
    struct Tweet *tweet;
    struct User *user[501];
    int timestamp;
  } Twitter;
 ```
  每个 User 都有自己的 Tweet 和 follow 列表，当需要输出自己和 follow 的前 10 条 tweet 时，  
  将需要计算的几个 tweet 列表集中到 `struct Tweet **res;` 中，然后用上一题的 `mergeKLists`  
  来将所有的列表按照时间顺序排列，输出前 10 个。  

44. [reverseBetween](https://leetcode-cn.com/problems/reverse-linked-list-ii/)  
  这题思路不难，主要是实现需要想清楚，之后遇到链表的题目要画图帮助理解。  
  记录 left 的前一个节点和 right 的后一个节点，用于之后的链接。  
  记录 reverse list 的头尾节点，用于链接。  

### reference
[1] https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E9%AB%98%E6%A5%BC%E6%89%94%E9%B8%A1%E8%9B%8B%E8%BF%9B%E9%98%B6.md
