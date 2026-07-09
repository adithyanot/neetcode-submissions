class Solution {
public:
    double myPow(double x, int n) {
        if(n ==0){
            return 1;
        }
        if(n<0){
            return 1/myPow(x,-1*n);
        }
        if(n==1){
            return x;
        }
        if(n&1){
            return x*myPow(x,n-1);
        }else{
            double temp = myPow(x,n/2);
            return temp*temp;
        }        
    }
};
