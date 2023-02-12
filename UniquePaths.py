class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0 for i in range(n)] for j in range(m)]
        dp[0][0] = 1
        for y in range(m):
            for x in range(n):
                if x == 0 and y == 0:
                    continue
                left = 0 if x == 0 else dp[y][x-1]
                right = 0 if y == 0 else dp[y-1][x]
                dp[y][x] = left+right
        return dp[m-1][n-1]