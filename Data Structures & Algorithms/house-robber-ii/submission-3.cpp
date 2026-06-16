class Solution {
public:
    int robhouse(vector<int> nums){
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> maxrob(n,0);
        
        maxrob[0] = nums[0];
        maxrob[1] = nums[1];
        for(int i=2;i<n;i++){  
            maxrob[i] = nums[i]+ max(maxrob[i-2],maxrob[i-1]-nums[i-1]);
        }
        return max(maxrob[n-1],maxrob[n-2]);

        

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int res1 = robhouse(vector<int>(nums.begin()+1,nums.end()));
        int res2 = robhouse(vector<int>(nums.begin(),nums.end()-1));
        return max(res1,res2);
       
        
    }
};
