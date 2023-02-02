class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0, L = 0, R = height.length-1;
        while(L != R){
            int area = Math.min(height[L], height[R]) * (R-L);
            if(area>maxArea){
                maxArea = area;
            }
            if(height[L]>height[R]){
                R-=1;
            }
            else{
                L+=1;
            }
        }
        return maxArea;
    }
}