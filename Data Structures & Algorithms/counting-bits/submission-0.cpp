class Solution {
public:
    int countones(int n){
        int count =0;
        while(n){
            count+= n&1;
            n = n >>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0;i<=n;i++){
            res[i] = countones(i);
        }
        return res;
    }
};
