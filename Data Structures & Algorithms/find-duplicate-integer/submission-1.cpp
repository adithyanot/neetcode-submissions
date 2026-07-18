class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i =0;
        int curr;
        while(i<nums.size()+1){
            curr = nums[i];
            if(curr == -1){
                return i;
            }
            nums[i] = -1;
            i = curr;
    
        }
        return -1;
        
    }
};
