class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<int, int> dict;
        while(r<nums.size()){
            dict[nums[r]]+=1;
            while(dict[nums[r]] > k){
                dict[nums[l]]-=1;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

