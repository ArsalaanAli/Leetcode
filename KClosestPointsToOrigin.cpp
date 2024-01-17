class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(auto point : points){
            pq.push({point[0]*point[0] + point[1]*point[1], point[0], point[1]});
        }
        vector<vector<int>> ans;
        for(int i = 0; i<k; i++){
            vector<int> top = pq.top(); 
            ans.push_back({top[1], top[2]});
            pq.pop();
        }
        return ans;
    }
};

