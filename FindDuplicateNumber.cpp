class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int d = nums[nums[0]];
        while(s!=d){
            s = nums[s];
            d = nums[nums[d]];
        }
        s = 0;
        while(s!=d){
            s = nums[s];
            d = nums[d];
        }
        return s;
    }
};