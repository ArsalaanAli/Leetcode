class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> done;
        recurse(done, candidates, 0, 0, target, result);
        return result;
    }
    void recurse(vector<int>& done, vector<int>& candidates, int start, int curSum, int target, vector<vector<int>>& result){
        if(curSum > target){
            return;
        }
        if(curSum == target){
            result.push_back(done);
            return;
        }
        for(int i = start; i<candidates.size(); i++){
            done.push_back(candidates[i]);
            curSum+=candidates[i];
            recurse(done, candidates, start, curSum, target, result);
            done.pop_back();
            curSum-=candidates[i];
            start++;
        }
    }
};