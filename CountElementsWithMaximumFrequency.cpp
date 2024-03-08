class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxF = 0;
        int numMax = 0;
        for(int i : nums){
            freq[i]++;
            if(freq[i] > maxF){
                maxF = freq[i];
                numMax = 1;
            }
            else if(freq[i] == maxF){
                numMax+=1;
            }
        }
        return maxF * numMax;

    }
};


