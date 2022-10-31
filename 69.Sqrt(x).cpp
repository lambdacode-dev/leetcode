class Solution {
public:
    int mySqrt(int x) {
        //[binary search] between 0  and max(2,x)
        //(time, space) = O(logN) O(1)
        int a = 0;
        int b = max(2,x);
        while(a < b) {
            int mid = (a+b)/2;
            if(mid == a || mid == x/mid)
                return mid;
            if(mid > x/mid) 
                b = mid;
            else
                a = mid;
        }
        return a;
    }
};
