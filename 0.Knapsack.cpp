#include "stdc++.h"
using namespace std;
//dp_i(c) = total val, for sub problem [0,i) with capacity c
//base: dp_0(c) = 0 for all c
//iteration: dp_i(c) -> dp_(i+1)(c+w) = dp_i(c) + v, where (v,w) = value weight of item [i]
//           dp_i(c) -> dp_(i+1)(c) = dp_i(c)
//[iterative DP]
//(time, space) = O(N*C) O(C) where N is # items and C the capacity
//
int knacksack(vector<array<int,2>> const& vw /*value,weight pair*/, int capacity) {
    vector<int> dp(capacity+1);
    for(auto const& [v,w] : vw) {
        vector<int> dp2(dp) ;
        for(int c = capacity - w; c >= 0; --c) {
            dp2[c+w] = max(dp2[c+w], dp[c] + v);
        }
        dp = std::move(dp2);
    }
    return dp.back();
}

int main() {
    cout << knacksack(vector<array<int,2>>{{10,1}, {15,2}, {40,3}}, 6) << endl;
    return 0;
}



