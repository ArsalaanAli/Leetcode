class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mx = prices[-1]
        ans = 0
        for i in prices[::-1]:
            if (mx - i) > ans:
                print(mx, i)
                ans = mx - i
            if i > mx:
                mx = i
        return ans