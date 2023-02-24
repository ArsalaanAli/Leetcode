class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        x = sum(range(len(nums)+1))
        for i in nums:
            x -= i
        return x
