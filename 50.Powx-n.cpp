class Solution {
    //[divide and conquer]
    //(time, space) = O(logN) O(1)
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(n < 0) 
            return 1.0/myPow(x, -(n+1))/x;
        if(n & 0b01) 
            return myPow(x, n-1) * x;
        auto p = myPow(x, n/2);
        return p * p;
    }
};
