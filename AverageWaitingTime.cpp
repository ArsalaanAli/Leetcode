class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int wait = 0;
        long long totTime = 0;
        for(auto cus : customers){
            wait = max(wait, cus[0]);
            wait += cus[1];
            totTime += wait-cus[0];
        }
        
        return (double) totTime/customers.size();
    }
};

