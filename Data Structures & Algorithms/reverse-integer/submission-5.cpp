class Solution {
public:
    int reverse(int x) {
        if(x ==0 || x == INT_MIN){
            return 0;
        }
        if(x<0){
            return -1 * reverse(-1*x);
        }
        int res=0;
        while(x){
            int digit = x%10;
            if(res> INT_MAX/10 || (res == INT_MAX/10 && digit > INT_MAX%10)){
                return 0;
            }
            res = res*10;
            res += digit;
            x = x/10;
            
        }
        return res;
        
    }
};
