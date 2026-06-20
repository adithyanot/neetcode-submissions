class Solution {
public:
    bool isvalid(string s,unordered_map<string,bool>& mp){
        if(!s.size()){
            return true;
        }
        if(mp.find(s) != mp.end()){
            return mp[s];
        }
        for(int i=1;i<s.size();i++){
            bool leftvalid = isvalid(s.substr(0,i),mp);
            bool rightvalid = isvalid(s.substr(i,s.size()-i),mp);
            if(leftvalid && rightvalid){
                mp[s] = true;
                return true;
            }

        }
        mp[s] = false;
        return false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mp;
        for(auto word: wordDict){
            mp[word] = true;
        }
        return isvalid(s,mp);
        
    }
};
