class Solution {
public:
    int search(vector<int>& nums, int target) {
        //[5 7 1 2 3] L>R
        //[3 5 1 2] L>R
        //[2 3 5 7 1] L>R
        //[7 1 2 3 5] L>R
        // l t m   r
        //if l<r: sorted, use binary search

        //t < r and t < l so right side
        //t < r and t > l
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m] == target){
                return m;
            }
            if(nums[l]<nums[r]){
                if(nums[m]>target){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            else{
                if(nums[m]>nums[r]){
                    if(target > nums[m] || target <= nums[r]){
                        l = m+1;
                    }
                    else{
                        r = m-1;
                    }
                }
                else{
                    if(target < nums[m] || target > nums[r]){
                        r = m-1;
                    }
                    else{
                        l = m+1;
                    }
                }
            }
        }
        return -1;
    }
};