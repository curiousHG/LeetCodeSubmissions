class Solution {
public:
    double myPow(double x, int n) {
        if(n>=0)return p(x,n);
        else return neg(x,n);
    }
    double p(double x,int n){
        if(n==0)return 1;
        else if(n%2){
            double y = p(x,n/2);
            return x*y*y;
        }else{
            double y = p(x,n/2);
            return y*y;
        }
    }
    double neg(double x, int n){
        if(n==-1)return 1/x;
        else if(abs(n)%2){
            double y = neg(x, n/2);
            return y*y/x;
        }else{
            double y = neg(x, n/2);
            return y*y;
        }
    }
};