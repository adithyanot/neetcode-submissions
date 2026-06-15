class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector<int> maxrob(n);
        maxrob[0] = nums[0];
        maxrob[1] = nums[1];
        for(int i=2;i<n;i++){
            maxrob[i] = nums[i] + max(maxrob[i-2],maxrob[i-1]-nums[i-1]);

        }
        return max(maxrob[n-1],maxrob[n-2]);

        
    }
};
