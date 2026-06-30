class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int sum = nums[i];
            res = max(res,sum);
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                res = max(res,sum);
            }
        }
        return res;

    }
};
