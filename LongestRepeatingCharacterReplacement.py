class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        check = dict()
        l, r, ans, maxValue = 0, 0, 0, 1
        check[s[l]] = 1
        while r<len(s):
            if (r-l+1) - maxValue <= k:
                ans = max(r-l+1, ans)
            else:
                while (r-l+1) - maxValue > k:
                    check[s[l]]-=1
                    l+=1
            r+=1
            if r>=len(s):
                break
            if s[r] in check:
                check[s[r]] += 1
                maxValue = max(maxValue, check[s[r]])
            else:
                check[s[r]] = 1
        return ans