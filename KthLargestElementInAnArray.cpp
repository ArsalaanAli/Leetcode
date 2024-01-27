class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

/*
SOLUTION WITH QUICK SELECT ALGORITHM (DOESNT WORK ON LEETCODE ANYMORE)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int r = nums.size()-1;
        int l = 0;
        int part = l;
        int target = nums.size()-k;
        while(true){
            for(int i = l; i<r; i++){
                if(nums[i]<nums[r]){
                    swap(nums[i], nums[part]);
                    part++;
                }
            }
            swap(nums[r], nums[part]);
            if(part == target){
                break;
            }
            if(part<target){
                part++;
                l = part;
            }
            else{
                r = part-1;
                part = l;
            }
        }
        return nums[part];
    }
};*/