class Solution {
public:
    int dfs(unordered_map<int,vector<int>>&mp,int i,int p,set<int>& visit){
        if(visit.find(i)!= visit.end()){
            return 0;
        }
        visit.insert(i);
        for(int j=0;j<mp[i].size();j++){
            if(mp[i][j]!=p){
                 dfs(mp,mp[i][j],i,visit);
            }
           
        }
        return 1;


    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
     
        }
        set<int>visit;
        int count =0;
        for(int i=0;i<n;i++){
            if(visit.find(i)==visit.end()){
                dfs(mp,i,-1,visit);
                count++;
            }
        }
        return count;

     



    }
};
