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
        backtrack(nums,subset,res,i+1);
        return;



    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        backtrack(nums,subset,res,0);
        set<vector<int>> s(res.begin(),res.end());
        res.assign(s.begin(),s.end());
        return res;


        
    }
};
