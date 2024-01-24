//Lintcode
class Solution {
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        int l = 0;
        int r = num.size()-1;
        while(l<=r){
            if (num[l] == '1' || num[l] == '8' || num[l] == '0'){
                if(num[r]!=num[l]){
                    return false;
                }
            }
            else if(num[l] == '6'){
                if(num[r] != '9'){
                    return false;
                }
            }
            else if(num[l] == '9'){
                if(num[r] != '6'){
                    return false;
                }
            }
            else{
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};