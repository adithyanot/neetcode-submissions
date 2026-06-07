class Solution {
public:
void dfs(unordered_map<int,vector<int>>&mp,int i, vector<int>& res,set<int>&visited){
        vector<int> prq = mp[i];
        if(!prq.size()){
            int cnt = count(res.begin(),res.end(),i);
            if(cnt==0){
                res.push_back(i);
            }
            return;
        }
        if(visited.find(i) != visited.end()){
            res = {};
            return;
        }
        visited.insert(i);
        for(int j=0;j<prq.size();j++){
            dfs(mp,prq[j],res,visited);
            if(!res.size()){
                return;
            }
        }
        visited.erase(i);
        res.push_back(i);
        mp[i] = {};




    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int,vector<int>>mp;
       vector<int> res={};
       for(int i=0;i<numCourses;i++){
        mp[i] = {};
       }
       for(int i=0;i<prerequisites.size();i++){
        mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
       }
       set<int> visited;
       for(auto i:mp){
        dfs(mp,i.first,res,visited);
        if(!res.size()){
            return {};
        }
       }
       return res;
       
        
    }
};
