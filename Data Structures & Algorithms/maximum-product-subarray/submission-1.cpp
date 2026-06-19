class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int prod = nums[i];
            maxprod = max(maxprod,prod);
            for(int j=i+1;j<nums.size();j++){
                prod*= nums[j];
                maxprod = max(maxprod,prod);


            }
        }
        return maxprod;
        
    }
};
