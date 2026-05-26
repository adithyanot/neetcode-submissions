class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size() ==0){
            ans.push_back({""});
            return ans;

        }
        if(strs.size() ==1){
            ans.push_back(strs);
            return ans;
        }
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            vector<int> c(26,0);
            for(int j=0;j<strs[i].size();j++){
                c[strs[i][j] - 'a'] +=1;
            }
            string key = to_string(c[0]);
            for(int k=1;k<26;k++){
                key += ',' + to_string(c[k]);
            }
            m[key].push_back(strs[i]);
            
        }

        for(auto i = m.begin() ; i != m.end(); i++){
            ans.push_back(i->second);
        }
        return ans;
     

        
    }
};
