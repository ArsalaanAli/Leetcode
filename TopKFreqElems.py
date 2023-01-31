class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ans = dict()
        for n in nums:
            if n in ans:
                ans[n]+=1
            else:
                ans[n]=1
        freq = [[] for i in range(len(nums)+1)]
        for key, val in ans.items():
            freq[val].append(key)
        out = []
        for i in range(len(freq)-1, -1, -1):
            for n in freq[i]:
                out.append(n)
                if len(out) == k:
                    return out