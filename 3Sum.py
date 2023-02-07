class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        for index, a in enumerate(nums):
            if index>0 and a == nums[index-1]:
                continue
            l,r = index+1, len(nums)-1
            while l<r:
                s = nums[l]+nums[r]+a
                if s>0:
                    r-=1
                elif s<0:
                    l+=1
                else:
                    ans.append([nums[index], nums[l], nums[r]])
                    l+=1
                    while nums[l] == nums[l-1] and l<r:
                        l+=1
        return ans