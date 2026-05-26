class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        vector<int> ans(2);
        for(int i=0;i<nums.size();i++){
            int dif = target - nums[i];
            if(s.find(dif)!= s.end()){
                return {s[dif],i};  
            }
            s[nums[i]] =i;
            
            
        }
        return ans;
       
    }
        
    
};
