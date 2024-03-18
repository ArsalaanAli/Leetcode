class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result;
        sort(nums.begin(), nums.end());
        recurse(0, result, nums, ans);
        return ans;
    }
    void recurse(int start, vector<int>& result, vector<int>& nums, vector<vector<int>>& ans){
        ans.push_back(result);
        for(int i = start; i<nums.size(); i++){
            if(i != start && nums[i] == nums[i-1]){
                continue;
            }
            result.push_back(nums[i]);
            recurse(i+1, result, nums, ans);
            result.pop_back();
        }
    }
};