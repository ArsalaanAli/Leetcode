class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = [(temperatures[0], 0)]
        ans = [0]*len(temperatures)
        for ind, val in enumerate(temperatures[1::]):
            while len(stack) > 0 and stack[-1][0] < val:
                ans[stack[-1][1]] = ind+1 - stack[-1][1]
                stack.pop()
            stack.append((val, ind+1))
        return ans