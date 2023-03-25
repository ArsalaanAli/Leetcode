class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        steps = [1, 2]
        for i in range(3, n+1):
            steps.append(steps[-1]+steps[-2])
        return steps[-1]