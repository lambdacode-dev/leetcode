class Solution {
    //[hashing] to check endless loop
    //(time, space) = O(logN) O(logN)
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(n != 1) {
            if(! visited.insert(n).second )
                return false;
            
            auto n2 = 0;
            for(; n; n /= 10) {
                auto ones = n % 10;
                n2 += ones * ones;
            }
            n = n2;
        }
        return true;
    }
};
