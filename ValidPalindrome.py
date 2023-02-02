class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s)-1
        s = s.lower()
        while l<=r:
            if l >= len(s):
                return True
            while not (s[l].isalpha() or s[l].isnumeric()):
                l+=1
                if l >= len(s):
                    return True
            while not (s[r].isalpha() or s[r].isnumeric()):
                r-=1
            if(l>r):
                return True
            if s[l] != s[r]:
                return False
            l+=1
            r-=1
        return True