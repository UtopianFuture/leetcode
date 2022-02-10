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

13. [strStr](https://leetcode-cn.com/problems/implement-strstr/)  
  这题用暴力解法法超时，需要使用 kmp 算法。使用 kmp 算法解决字符匹配类问题的关键就是 pat 字符串的 kmp 数组。  
  然后根据 kmp 数组求解。  
  每个字符串对应的 kmp 数组是确定的，可以用这个算法来求:  
    ```
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
    ```
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
  这题的做法很巧妙，求最短回文串，用暴力的解法比较简单，将后面的字符和前面的字符一个个遍历对比，如果不相同，则插入。  
  而 KMP 算法是先求出原字符串的 next 数组，然后将字符串反转等到 txt 数组。之后按照 kmp 遍历，看 txt 数组的最后一个字符  
  对应 next 数组的哪个字符，将该字符之后的字符都加入到 txt 数组。  

16. [longestPalindrome](https://leetcode-cn.com/problems/longest-palindromic-substring/)  
  - 原做法（错误）
  这题没有使用 kmp 算法，而是使用动态规划，`dp[i][j]` 表示 `s[i ~ j]` 的最长回文串，  
  注意这里还需要考虑一个事情  
    ```
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
  （1）如果该子串 `s[i] != s[j]`， 那么这个子串肯定不会回文；  
  （2）如果 `s[i] == s[j]`，那么该子串是否是回文跟 `s[i + 1] ~ s[j - 1]` 相同。  
  
  还有一点需要注意，由于使用了 `-fsanitize=address` 来进行边界检查，所以在创建 `char *` 时要这样  
    ```
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
    ```
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
    ```
    // 今天没有持有股票，可能是保持昨天的状态，也可能是昨天持有股票，但是今天卖了
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    // 今天没有持有股票，可能是保持昨天的状态，也可能是今天买入股票，那么最大交易次数就减 1。
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
    ```

18. [maxProfit_ii](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)  
  dp base 还是和上题一样  
    ```
    int dp_0 = 0, dp_1 = 0x80000001;
    ```
  状态转移方程也是一样的，  
    ```
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
    ``` 
  但是 k 是无限的，`[k]` 和 `[k - 1]` 一样，可以约掉，  
  得到如下状态转移方程，
    ```
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])
    ```
  那么 k 成为无关状态，  
    ```
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
    ```
  再将 `dp[i][0]` 化简为 `dp_0`，这里有一点需要注意，`dp[i][0]` 表示的是上一天的利润，  
  换成 `dp_0` 后  
    ```
    dp_0 = max(dp_0, dp_1 + prices[i]);
    dp_1 = max(dp_1, dp_0 - prices[i]);
    ```
  `dp_0` 已经经过计算，变成今天的利润，所以要利用一个 temp 来记录昨天的利润。  

19. [maxProfit_iii](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)  
  这题是上一题的进一步，`k = 2`，之后类似的题目都是套这种模板，  
  #### dp base  
    ```
    for (int i = 0; i < pricesSize; i++) {
      dp_0[i][0] = 0;
      dp_1[i][0] = -prices[i];
    }
    ```
  因为 i 是从 0 开始的，所有要初始化 `i - 1 == -1` 的情况，  
    ```
    if (i - 1 == -1) {
      dp_0[i][k] = 0;
      dp_1[i][k] = -prices[i];
      continue;
    }
    ```
20. [maxProfit_iv](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)  
  `k = integer`，但是如果 `k > days / 2` 的就和 `k = inf` 一样的，所以在上一题的基础加上加一个限制条件即可  
    ```
    if (k > pricesSize / 2) {
      return maxProfit_inf(prices, pricesSize);
    }
    ```
21. [maxProfit_freeze](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)  
  这题在 18 的基础上简单修改一下即可，冰冻期为 n 则状态转移方程变为：  
    ```
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-n][k][0] - prices[i])
    ```
  然后一样，k 变成无关变量，可以约掉。  

22. [maxProfit_fee](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)  
  这题还是 18 的变种，只需要在收入上减去 fee 即可。  
    ```
    dp_0 = dp_0 > dp_1 + prices[i] - fee ? dp_0 : dp_1 + prices[i] - fee;
    ```
23. [rob](https://leetcode-cn.com/problems/house-robber/)  
  这题比较简单，用一个一维的 dp 数组表示到当前房间时最高金额。
  #### dp base  
    ```
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
  #### 状态转移方程  
    ```
    dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i]
    ```
24. [rob_ii](https://leetcode-cn.com/problems/house-robber-ii/)  
  首尾是连接的，那么就分两种情况考虑，
  （1）抢劫 first house 不抢劫 last house  
    ```
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[2] + dp[0];
    for (int i = 3; i < numsSize - 1; i++) { // don't rob the last house
      dp[i] = dp[i - 2] > dp[i - 3] ? dp[i - 2] + nums[i] : dp[i - 3] + nums[i];
    }
    ```
  （2）抢劫 last house 不抢劫 first house  
    ```
    dp[1] = nums[1];
    dp[2] = nums[2];
    dp[3] = nums[3] + dp[1];
    for (int i = 4; i < numsSize; i++) { // don't rob the first house
      dp[i] = 0;
      dp[i] = dp[i - 2] > dp[i - 3] ? dp[i - 2] + nums[i] : dp[i - 3] + nums[i];
    }
    ```
  返回大的哪个。  

25. [rob_iii](https://leetcode-cn.com/problems/house-robber-iii/)  
  这题虽然用的也是和上题类似的动态规划思路，但由于需要遍历的是二插树，又有些不一样。  
  每个节点可能被抢也可能没被抢，定义一个结构体来表示每个节点的状态，   
    ```
    struct status {
    int do_rob; // 该 house 被抢劫后的总金额
    int dont_rob; // 该 house 没被抢劫的总金额
    };
    ```
  遍历每个节点，  
  ```
  struct status left = dp(node->left);
  struct status right = dp(node->right);
  ```
  而该节点的状态是这样的，  
  ```
  // 如果该节点被抢劫，那么总金额为该节点的金额加上子结点没有被抢劫的金额
  int do_rob = node->val + left.dont_rob + right.dont_rob;
  // 如果该节点没有被抢劫，那么子结点可被抢也可不被抢，总金额为大的那个
  int dont_rob =
      (left.do_rob > left.dont_rob ? left.do_rob : left.dont_rob) +
      (right.do_rob > right.dont_rob ? right.do_rob : right.dont_rob);
  ```

26. [isMatch_regular](https://leetcode-cn.com/problems/regular-expression-matching/)  
  这题开始想错了方向，想着直接使用 kmp 字符匹配，然后对 '.', '*' 对特殊处理即可，  
  例如：  
  ```
  if ((p[i] == '*' && (p[i - 1] == s[j] || p[i - 1] == '.')) ||
    p[i] == s[j] || p[i] == '.') {
    j++;
  }
  ```
  但是没有抓住问题的关键，即 '*' 的匹配的次数，可以为任意次。  
  那么当 `p[i + 1] == '*'` 时，我们遍历所有的情况，即匹配 0 次或多次。  
  ```
  if (p[j + 1] == '*') {
      // "j + 2" - '*' match 0 time, "i + 1" - '*' match 1 time
      // dp(s, i + 1, p, j) can match many times
      res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
    }
  ```
  但关键是这点想不到啊。  
  
### reference
[1] https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E9%AB%98%E6%A5%BC%E6%89%94%E9%B8%A1%E8%9B%8B%E8%BF%9B%E9%98%B6.md
