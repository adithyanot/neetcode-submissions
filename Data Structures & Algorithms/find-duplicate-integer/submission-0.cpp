class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i =0;
        while(i<nums.size()+1){
            int curr = nums[i];
            if(curr == -1){
                return i;
            }
            nums[i] = -1;
            i = curr;
    
        }
        return -1;
        
    }
};
