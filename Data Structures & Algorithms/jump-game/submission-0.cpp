class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>res(nums.size(),false);
        res[0]=true;
        for(int i=0;i<nums.size();i++){
            if(res[i] == true){
                for(int j=1;j<nums[i]+1;j++){
                res[i+j] = true;
            }

            }
            
        }
        return res[nums.size()-1];
        
    }
};
