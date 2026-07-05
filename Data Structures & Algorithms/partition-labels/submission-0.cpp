class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> end;
        for(int i=0;i<s.size();i++){
            end[s[i]] = i;
        }
        int curr =0;
        int start =0;
        int end_ptr = end[s[curr]];
        vector<int>res;
        while(curr<s.size()){
            if(end_ptr ==curr){
                res.push_back(curr - start +1);
                curr++;
                start = curr;
                end_ptr = max(end_ptr,end[s[curr]]);
            }else{
                end_ptr = max(end_ptr,end[s[curr]]);
                curr++;
            }

        }
        return res;

    }
};
