class Solution {
public:
    void backtrack(vector<int>& nums,vector<int>& subset,vector<vector<int>>& res,int i){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums,subset,res,i+1);
        subset.pop_back();
        while(i+1 <nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        backtrack(nums,subset,res,i+1);

        return;



    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        backtrack(nums,subset,res,0);
  
        return res;


        
    }
};
