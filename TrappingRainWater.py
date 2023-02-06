class Solution:
    def trap(self, height: List[int]) -> int:
        maxL = [0] * len(height)
        maxR = [0] * len(height)
        s = 0
        for i in range(1, len(height)):
            maxL[i] = max(maxL[i-1], height[i-1])
        for i in range(len(height)-2, -1, -1):
            maxR[i] = max(maxR[i+1], height[i+1])
        for i in range(len(height)):
            diff = min(maxL[i], maxR[i]) - height[i]
            if diff>0:
                s+=diff
        return s