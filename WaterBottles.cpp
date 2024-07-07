class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = 0;
        while(numBottles >= numExchange){
            int extra = (int) numBottles/numExchange;
            drink += extra*numExchange;
            numBottles = (numBottles%numExchange)+extra;
        }
        drink += numBottles;
        return drink;
    }
};

