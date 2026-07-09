class Solution {
public:
    double myPow(double x, int n) {
        if(n ==0){
            return 1;
        }
        if(n<0){
            return 1/myPow(x,-1*n);
        }
        double res =x;
        for(int i=1;i<n;i++){
            res = res*x;
        }
        return res;
        
    }
};
