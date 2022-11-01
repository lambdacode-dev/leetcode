class Solution {
public:
    //[math]: x = n-1 + n + n+1 = num
    //(time, space) = O(1), O(1)
    vector<long long> sumOfThree(long long num) {
        return num % 3 ? {} :{ num/3 - 1, num/3, num/3 + 1};
    }
};
