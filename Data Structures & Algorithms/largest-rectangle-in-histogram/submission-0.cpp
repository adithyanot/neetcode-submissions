class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea =0;
        for(int i=0;i<n;i++){
            int min_h = INT_MAX;
            for(int j=i;j<n;j++){
                min_h = min(min_h,heights[j]);
                int area = (j-i+1) * min_h;
                maxarea = max(area,maxarea);
            }
        }
        return maxarea;
        
    }
};
