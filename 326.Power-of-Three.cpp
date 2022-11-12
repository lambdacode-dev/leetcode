template<int N> struct Power3 { constexpr static int val = Power3<N-1>::val * 3; };
template<> struct Power3<0> { constexpr static int val = 1; };

class Solution {
    //[binary search]
    //(time, space) = O(1) O(1)
public:
    bool isPowerOfThree(int n) {
        constexpr int power3[20] = { //3^0 ... 3^19
            Power3<0>::val,
            Power3<1>::val,
            Power3<2>::val,
            Power3<3>::val,
            Power3<4>::val,
            Power3<5>::val,
            Power3<6>::val,
            Power3<7>::val,
            Power3<8>::val,
            Power3<9>::val,
            Power3<10>::val,
            Power3<11>::val,
            Power3<12>::val,
            Power3<13>::val,
            Power3<14>::val,
            Power3<15>::val,
            Power3<16>::val,
            Power3<17>::val,
            Power3<18>::val,
            Power3<19>::val
            };

        if(n < 0 || ! (n & 0b01) ) return false;
        auto i = lower_bound(power3, power3+20, n);
        return i != power3+20 && *i == n;
    }
};
