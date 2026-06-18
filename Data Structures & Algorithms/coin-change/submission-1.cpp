class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0){
            return 0;
        }
        unordered_map<int,int> dp(amount+1);
        dp[0] = 0;
        for(int i=1;i<= amount;i++){
            dp[i] = -1;
            int mini =INT_MAX;
            for(int j=0;j<coins.size();j++){
                int temp = i -coins[j];
                if(dp.find(temp)==dp.end()){
                    continue;
                }
                if(dp[temp]>=0){
                    mini = min(mini,1+dp[temp]);
                }
            }
            if(mini != INT_MAX){
                dp[i] = mini;
            }
        }
        return dp[amount];
   

        
    }
};
