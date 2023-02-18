class Solution:
    def reverse(self, x: int) -> int:
        neg = False
        if x<0:
            neg = True
        x = str(x)
        x = x[::-1]
        if neg:
            x = x[0:-1]
        x = int(x)
        if neg:
            x*=-1
        if abs(x) >= 2**31:
            return 0
        return (x)