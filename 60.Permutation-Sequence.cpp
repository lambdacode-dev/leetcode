class Solution {
    class Solution {
    //[number system with factorial weights]
    //(time,space) = O(N^2) O(N)
    template<int N> struct F { constexpr static int val = F<N-1>::val*N; }; // factorial n!
    template<> struct F<1> { constexpr static int val = 1; };
    static constexpr int weight[9] = { 1, F<1>::val, F<2>::val, F<3>::val, F<4>::val, F<5>::val, F<6>::val, F<7>::val, F<8>::val };
public:
    string getPermutation(int n, int k) {
        string permu;
        vector<bool> taken(n, false);
        --k; // make k 0-based as needed for modular operation
        while(n) {// pick (k/weight[n-1])-th (0-based) available number in this iteration
            for(int j = 0, i = k / weight[n-1] + 1; j < taken.size(); ++j) {
                if(!taken[j] && !--i) {
                    taken[j] = true;
                    permu.push_back('0'+j+1);
                    break;
                }
            }
            k %= weight[n-- -1];
        }
        return permu;
    }
};
