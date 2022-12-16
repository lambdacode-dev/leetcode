//[dynamic programm] f_n(j)[2] = sub problemn of form decreasing/increasing n-team from [0, j], with last member[j]
//base f_1(j)[2] = {1} for all j
//(time, space) = O(N^2) O(N)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<int> dp[2] = { vector<int>(rating.size(), 1), vector<int>(rating.size(), 1) };
        for(int n = 2; n <= 3; ++n) {
            for(int j = rating.size()-1; j >= n-1; --j) {
                dp[0][j] = dp[1][j] = 0;
                for(int i = n-2; i < j; ++i) {
                    if(rating[j] > rating[i])
                        dp[1][j] += dp[1][i];
                    else if(rating[j] < rating[i])
                        dp[0][j] += dp[0][i];
                }
            }
        }
        return accumulate(dp[0].begin()+2, dp[0].end(), 0) + accumulate(dp[1].begin()+2, dp[1].end(), 0);
    }
}
