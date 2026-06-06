class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp,int i,bool& res,set<int>&visited){
        vector<int> prq = mp[i];
        if(!prq.size()){
            return;
        }
        if(visited.find(i) != visited.end()){
            res = true;
            return;
        }
        visited.insert(i);
        for(int j=0;j<prq.size();j++){
            dfs(mp,prq[j],res,visited);
        }
        visited.erase(i);
        mp[i] = {};




    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       unordered_map<int,vector<int>>mp;
       bool res = false;
       for(int i=0;i<numCourses;i++){
        mp[i] = {};
       }
       for(int i=0;i<prerequisites.size();i++){
        mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
       }
       set<int> visited;
       for(auto i:mp){
        dfs(mp,i.first,res,visited);
        if(res){
            return false;
        }
       }
       return true;



        
    }
};
