class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        for(int i = 1; i<=n; i++){
            circle.push_back(i);
        }
        int pos = k-1;
        while(circle.size()>1){
            cout<<circle[pos]<<endl;
            circle.erase(circle.begin()+pos);
            pos = (pos+k-1) % circle.size();
        }
        return circle[0];
    }
};

