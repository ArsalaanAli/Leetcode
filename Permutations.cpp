class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        recurse(nums, 0, result);
        return result;
    }
    void recurse(vector<int>& nums, int marker, vector<vector<int>>& result){
        if(marker == nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i = marker; i<nums.size(); i++){
            swap(nums[i], nums[marker]);
            recurse(nums, marker+1, result);
            swap(nums[i], nums[marker]);
        }
    }
};