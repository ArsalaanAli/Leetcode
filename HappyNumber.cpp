class Solution {
public:
    bool isHappy(int n) {
        while(n!=1){
            int sum = 0;
            while(n>0){
                sum += pow(n%10, 2);
                n = n/10;
            }
            if(sum == 4){
                return false;
            }
            n = sum;
        }
        return true;
    }
};