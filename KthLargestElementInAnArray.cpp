class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pivot = nums[0]
        while(true){
            vector<int> less;
            vector<int> greater;
            for(int i : nums){
                if(i == pivot){
                    continue;
                }
                if(i>pivot){
                    greater.push_back(i);
                }
                else{
                    less.push_back(i);
                }
            }

        }
    }
};