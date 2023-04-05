class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        d1 = [0]*26
        d2 = [0]*26
        for i in s1:
            d1[ord(i)-ord('a')]+=1
        for i in range(len(s1)):
            d2[ord(s2[i]) - ord('a')]+=1
        match = 0
        for i in range(26):
            if d1[i] == d2[i]:
                match+=1
        start = 0
        while match != 26:
            if start + 1 + len(s1) > len(s2):
                break
            f = s2[start]
            d2[ord(f)-ord('a')]-=1
            if d2[ord(f)-ord('a')] == d1[ord(f)-ord('a')]:
                match += 1
            elif d2[ord(f)-ord('a')] + 1 == d1[ord(f)-ord('a')]:
                match -= 1
            start += 1
            l = s2[start + len(s1)-1]
            d2[ord(l)-ord('a')] += 1
            if d2[ord(l)-ord('a')] == d1[ord(l)-ord('a')]:
                match += 1
            elif d2[ord(l)-ord('a')] - 1 == d1[ord(l)-ord('a')]:
                match -= 1
        if match == 26:
            return True
        return False