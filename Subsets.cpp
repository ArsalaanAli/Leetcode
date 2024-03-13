class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> done;
        recurse(0, done, nums, result);
        return result;
    }
    void recurse(int start, vector<int>& done, vector<int>& nums,  vector<vector<int>>& result){
        result.push_back(done);
        for(int i = start; i<nums.size(); i++){
            done.push_back(nums[i]);
            recurse(i+1, done, nums, result);
            done.pop_back();
        }
    }
};