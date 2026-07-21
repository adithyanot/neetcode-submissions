class Solution {
    unordered_map<char,vector<char>>mp;
    

public:
    vector<string> letterCombinations(string digits) {
    mp['2'] = {'a','b','c'};
    mp['3'] = {'d','e','f'};
    mp['4'] = {'g','h','i'};
    mp['5'] = {'j','k','l'};
    mp['6'] = {'m','n','o'};
    mp['7'] = {'p','q','r','s'};
    mp['8'] = {'t','u','v'};
    mp['9'] = {'w','x','y','z'};
        if(digits.size() ==0){
            return {};
        }
        vector<string> vs;
        vector<string> vs_new;
        for(auto i: digits){
            for(int j=0;j<mp[i].size();j++){
                if(vs.size()!= 0 ){
                    for(int k=0;k<vs.size();k++){
                        vs_new.push_back(vs[k] + mp[i][j]);
                    }
                }else{
                    string temp;
                    temp += mp[i][j];
                    vs_new.push_back(temp);

                }

            }
            vs = vs_new;
            vs_new={}; 
        }

        return vs;

        
    }
};
