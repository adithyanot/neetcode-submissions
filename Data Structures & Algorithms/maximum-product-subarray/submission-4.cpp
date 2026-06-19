class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = INT_MIN;
        int prod = nums[0];
        maxprod = max(maxprod,prod);
        for(int i=1; i<nums.size();i++){
             if(prod==0){
                prod =1;
            }
            prod*= nums[i];
            maxprod = max(maxprod,prod); 
        }
        prod = nums[nums.size()-1];
        maxprod = max(maxprod,prod);
        for(int i=nums.size()-2;i>=0;i--){
            if(prod==0){
                prod =1;
            }
            prod*= nums[i];
            maxprod = max(maxprod,prod);
        }
        return maxprod;
        
    }
};
