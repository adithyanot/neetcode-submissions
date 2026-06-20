class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0] = 1;
        int ans = 1;
        for(int i=1;i<nums.size();i++){
            res[i] =1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    res[i] = max(res[i],res[j]+1);

                }

            }
            ans = max(ans,res[i]);
        }
        return ans;


        
    }
};
