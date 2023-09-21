class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        deque<int> que;
        vector<int> ans;
        int i = 0;
        for(int j = 0; j<nums.size(); j++){
            if(que.empty()){
                que.push_back(nums[j]);
                continue;
            }
            if(nums[j] > que.front()){
                while(nums[j]>que.front() && !que.empty()){
                    que.pop_front();
                }
                que.push_front(nums[j]);
            }
            else{
                while(nums[j] > que.back() && !que.empty()){
                    que.pop_back();
                }
                que.push_back(nums[j]);
            }
            if(j >= k-1){
                ans.push_back(que.front());
                if(que.front() == nums[i]){
                    que.pop_front();
                }
                i++;
            }
        }
        
        return ans;
    }
};
