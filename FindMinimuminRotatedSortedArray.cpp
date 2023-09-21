class Solution {
public:
    int findMin(vector<int>& nums) {
        int  l = 0;
        int r = nums.size()-1;
        while(l<r){
            int mid = (r-l) / 2 + l;
            if(nums[l]>nums[r]){
                if(r==l+1){
                    return nums[r];
                }
                if(nums[mid]>nums[r]){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            else{
                return nums[l];
            }
        }
        return nums[l];
    }
};

