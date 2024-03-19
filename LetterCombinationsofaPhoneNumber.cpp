class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string cur = "";
        recurse(0, cur, result, digits);
        return result;
    }
private:
    vector<string> lets = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void recurse(int start, string& cur, vector<string>& result, string digits) {
        if (start == digits.size()) {
            if(cur != ""){
                result.push_back(cur);
            }
            return;
        }
        for (char l : lets[digits[start] - '0']) {
            cur += l;
            recurse(start + 1, cur, result, digits);
            cur.pop_back();
        }
    }
};

