class Solution {
public:
    int get_value(int n){
        int sum =0;
        while(n){
            sum += pow(n%10,2);
            n = n/10;
        }
        return sum;

    }
    bool isHappy(int n) {
        int val = get_value(n);
        unordered_map<int,int> mp;
        while(n!=1){
            if(mp[n]){
                return false;
            }
            mp[n] = get_value(n);
            n = mp[n];

        }
        return true;


       
       
    }
};
