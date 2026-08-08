class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int cur_len =1;
        int max_len = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] == nums[i-1]+1){
                cur_len ++;
                max_len = max(max_len,cur_len);
            }else{
                cur_len =1;

            }

        }
        return max_len;

    }
};
