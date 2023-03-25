class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        ans = [90000000000000000000]*(len(cost)+1)
        ans[0] = 0
        ans[1] = 0
        cost.append(0)
        for ind, val in enumerate(cost):
            if ind < len(cost)-1:
                ans[ind+1] = min(ans[ind+1], val+ans[ind])
            if ind < len(cost)-2:
                ans[ind+2] = min(ans[ind+2], val+ans[ind])
        print(ans)
        return ans[-1]