class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> mincosts(n+1,0);
        for(int i=2;i<=n;i++){
            mincosts[i] = min(mincosts[i-1]+cost[i-1],mincosts[i-2]+cost[i-2]);
        }
        return mincosts[n];
        
    }
};
