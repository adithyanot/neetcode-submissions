class Solution {
public:
    void dfs(vector<int>& nums, int target, vector<vector<int>>& res, 
             vector<int>& subset, int start) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (target < 0) return;
        
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            dfs(nums, target - nums[i], res, subset, i);  
            subset.pop_back(); 
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, target, res, subset, 0);
        set<vector<int>> s(res.begin(),res.end());
        res.assign(s.begin(),s.end());
        return res;
    }
};