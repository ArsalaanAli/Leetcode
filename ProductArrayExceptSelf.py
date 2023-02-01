class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        presum = [1]*len(nums)
        postsum = [1]*len(nums)
        for i in range(1, len(nums)):
            presum[i] = presum[i-1]*nums[i-1]
        for i in range(len(nums)-2, -1, -1):
            postsum[i] = postsum[i+1]*nums[i+1]
        ans = []
        print(presum)
        print(postsum)
        for i in range(len(nums)):
            ans.append(presum[i]*postsum[i])
        
        return ans