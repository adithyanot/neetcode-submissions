class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
        }
        if(target>sum){
            return 0;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,0));
        dp[0][sum+nums[0]] +=1;
        dp[0][sum-nums[0]]+=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if( j+nums[i] < dp[0].size() ){
                    dp[i][j] += dp[i-1][j+nums[i]];
                }
                if(0<= j-nums[i]  ){
                    dp[i][j] += dp[i-1][j-nums[i]];
                }

            }
        }
        return dp[nums.size()-1][target+sum];


        
    }
};
