class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()){
            return "";
        }
        unordered_map<char, int> cmap;
        for(int j = 0; j<t.length(); j++){
            cmap[t[j]]++;
        }
        int goal = cmap.size();
        int l = 0, r = 0, minL = 0, minR = 0, minSize = INT_MAX;

        while(r<s.length()){
            if(cmap.count(s[r])>0){
                cmap[s[r]]--;
                if(cmap[s[r]] == 0){
                    goal--;
                }
            }
            r++;
            while(goal==0){
                if(r-l < minSize){
                    minSize = r-l;
                    minL = l;
                    minR = r;
                }
                if(cmap.count(s[l]) > 0){
                    cmap[s[l]]++;
                    if(cmap[s[l]] == 1){
                        goal++;
                    }
                }
                l++;
            }
        }
        cout<<minL<<" "<<minR<<endl;
        return s.substr(minL, minR-minL);
    }
};