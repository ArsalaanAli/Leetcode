class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i = 0; i<4; i++){
            int l = i;
            int r = nums.size()-(4-i);
            int diff = nums[r]-nums[l];
            ans = min(ans, diff);
        }
        return ans;
    }
};
