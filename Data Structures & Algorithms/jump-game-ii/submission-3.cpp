class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> res(nums.size());
        res[nums.size()-1]=0;
        for(int i= nums.size()-2;i>=0;i--){
            int min_steps = INT_MAX;
            for(int j=1;j<=nums[i];j++){
                if(i+j < nums.size()){
                    if(res[i+j]!= INT_MAX){
                         min_steps = min(min_steps,res[i+j]+1);
                    }
                   
                } 
            }
            res[i] = min_steps;
            
        }
        return res[0];
    }
};
