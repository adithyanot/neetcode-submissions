class Solution {
public:
    bool target_sum(vector<int>& nums,int target,int start){
        if(target<0 || start>=nums.size()){
            return false;
        }
        if(target ==0){
            return true;
        }
        bool with = target_sum(nums,target-nums[start],start+1);
        if(with){
            return true;
        }
        bool without = target_sum(nums,target,start+1);
        if(without){
            return true;
        }
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
        return target_sum(nums,target,0);
        

        
    }
};
