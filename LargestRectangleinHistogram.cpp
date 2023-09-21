class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<int> stack;
        vector<int> index;
        int maxHeight = heights[0];
        stack.push_back(heights[0]);
        index.push_back(0);
        for(int i = 1; i < heights.size(); i++){
            int curInd = i;
            while(!stack.empty() && heights[i] < stack.back()){
                int popH = stack.back();
                int popI = index.back();
                stack.pop_back();
                index.pop_back();
                int area = (i - popI) * popH;
                maxHeight = max(maxHeight, area);
                curInd = popI;
            }
            stack.push_back(heights[i]);
            index.push_back(curInd);
        }
        return maxHeight;
    }
};
