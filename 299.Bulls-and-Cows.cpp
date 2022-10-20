class Solution {
public:
    //[frequency count]: scan left to right, match or count.
    //(time, space) = O(N) O(1)
    string getHint(string secret, string guess) {
        int sFreq[10] = {}; // digit frequency of secret
        int gFreq[10] = {}; // digit frequency of guess
        int bulls = 0;
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i])
                bulls++;
            else {
                sFreq[secret[i] - '0']++;
                gFreq[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for(int i = 0; i < 10; ++i) {
            cows += min(sFreq[i], gFreq[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
