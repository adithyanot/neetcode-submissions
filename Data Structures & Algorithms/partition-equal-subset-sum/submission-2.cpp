class Solution {
public:
    bool target_sum(vector<int>& nums,int target,int start,vector<vector<int>>&mem){
        
        if(target<0 || start>=nums.size()){
            return false;
        }
        if(mem[start][target] !=2){
            if(mem[start][target] ==1){
                return true;
            }
            return false;
        }
        if(target ==0){
            return true;
        }
        bool with = target_sum(nums,target-nums[start],start+1,mem);
        if(with){
            mem[start+1][target-nums[start]] = 1;
            return true;
        }
        bool without = target_sum(nums,target,start+1,mem);
        if(without){
            mem[start+1][target] = 1;
            return true;
        }
        mem[start][target]=0;
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum&1){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> memory(nums.size(),vector<int>(target+1,2));
        return target_sum(nums,target,0,memory);
        

        
    }
};
