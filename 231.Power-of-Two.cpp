class Solution {
    //[reset rightmost 1 bit]
    //(time, space) = O(1) O(1)
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !( n & (n-1) );
    }
};
