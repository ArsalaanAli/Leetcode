class MedianFinder {
public:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int curMed = findMedian();
        if(num <= curMed){
            low.push(num);
        }
        else{
            high.push(num);
        }
        balanceQueues();
    }
    
    double findMedian() {
        double curMed;
        if(low.size() == high.size()){
            if(low.size() == 0){
                return 0;
            }
            curMed = ((low.top() + high.top()) / 2.0);
        }
        else{
            curMed = low.size() > high.size() ? low.top() : high.top();
        }
        return curMed;
    }

private:
    void balanceQueues(){
        int left = low.size() - high.size();
        while(left < -1){
            low.push(high.top());
            high.pop();
            left++;
        }
        while(left > 1){
            high.push(low.top());
            low.pop();
            left--;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 