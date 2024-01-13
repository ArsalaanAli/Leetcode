class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        for(int i = 0; i<s.size(); i++){
            freq[t[i]-'a']--;    
        }
        for(int i : freq){
            if(i>0){
                ans+=i;
            }
        }
        return ans;
    }
};
