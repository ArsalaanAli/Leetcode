class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        check = set()
        ans = 0
        for n in nums:
            check.add(n)
        for i in range(len(nums)):
            cur = nums[i]
            if cur-1 in check:
                continue
            leng = 0
            while(cur in check):
                leng+=1
                cur+=1
            if leng>ans:
                ans = leng
        return ans
