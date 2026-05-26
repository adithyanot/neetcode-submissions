class Solution {
public:
    int trap(vector<int>& height) {
        int total=0;
        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        left_max[0] =0;
        right_max[n-1] = 0;
        for(int i=1;i<n;i++){
            left_max[i] = max(left_max[i-1],height[i-1]);

        }
        for(int i =n-2;i>=0;i--){
            right_max[i] = max(right_max[i+1],height[i+1]);

        }
        for(int i =0;i<n;i++){
            int col_cap = min(left_max[i],right_max[i]) - height[i];
            if(col_cap >0){
                total += col_cap;
            }

        }
        return total;
        
    }
};
