class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        unordered_map<char,int> mpt;
        unordered_map<char,int> mpw;

        for(int i =0;i<t.size();i++){
            mpt[t[i]]++;  
        }
    
        pair<int,int> p;
        int res_len = INT_MAX;
        int need = mpt.size();
        int have =0;
        int l =0;
        for(int r =0;r<s.size();r++){
            mpw[s[r]]++;
            if(mpt[s[r]] == mpw[s[r]]){
                have ++;
            }
            while(have == need){
                if(r-l+1 <res_len){
                    res_len = r-l+1;
                    p.first = l;
                    p.second = r;
                }
                mpw[s[l]]--;
                if(mpt[s[l]] > mpw[s[l]]){
                    have --;

                }
                l++;
            }

            
                
            
            



        }
        if(res_len == INT_MAX){
            return "" ;
        }
        return s.substr(p.first,p.second - p.first+1);
    }
};
