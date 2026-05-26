class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int>mp;
        mp['('] = 1;
        mp[')'] = 2;
        mp['['] = 3;
        mp[']'] = 4;
        mp['{'] = 5;
        mp['}'] = 6;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if((mp[s[i]] & 1) ==1){
                st.push(s[i]);
            }else if((mp[s[i]] & 1) ==0){
                // cout<<"im even"<<endl;
                if(st.empty()){
                    return false;
                }
                char c = st.top();
                st.pop();
                if(mp[c]+1 != mp[s[i]]){
                    return false;
                }


            }
        }
        if(!st.empty()){
            return false;
        }
        return true;;
        
    }
};
