class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0){
            return 0;
        }
        int tot = 1;
        int ans = 0;
        int l = 0;
        int r = 0;
        while(r!=nums.size()){
            tot*=nums[r];
            while(tot>=k && l<r){
                tot/=nums[l];
                l++;
            }
            if(tot<k){
                ans+=(r-l)+1;            
            }
            r++;
        }
        return ans;
    }
};

