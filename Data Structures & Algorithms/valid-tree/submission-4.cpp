class Solution {
public:
    int dfs(unordered_map<int,vector<int>>&mp, set<int>&visited, int i,int p){
        cout<<"i- "<<i<<endl;
        if(visited.find(i) != visited.end()){
            return 0;
        }
        vector<int> nbrs = mp[i];
        if(!nbrs.size()){
            return 1;
        }
        visited.insert(i);
        for(int j=0; j<nbrs.size();j++){
            if(nbrs[j] !=p ){
                if(!dfs(mp,visited,nbrs[j],i)){
                return 0;
            }
            }
            
        }
        return 1;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if(m>=n){
            return false;
        }
        if(edges.size()==0){
            return true;
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        set<int> visited;
        if(!dfs(mp,visited,0,-1)){
            return false;
        }
        if(visited.size()==n){
            return true;

        }
        return false;

        


    }
};
