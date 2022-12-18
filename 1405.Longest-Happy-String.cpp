class Solution {
    //[greedy to generate multiplicity array]
    //(time, space) = O(N) O(N)
public:
    string longestDiverseString(int a, int b, int c) {
        char letters[3] = {'a', 'b', 'c'};
        if(a < b) { swap(letters[0], letters[1]); swap(a,b); }
        if(a < c) { swap(letters[0], letters[2]); swap(a,c); }
        if(b < c) { swap(letters[1], letters[2]); swap(b,c); }
        int pairA = (a >> 1) + (a & 0b01);

        //2 occurrences of a in each group, except possibly last group being 1
        vector<array<int,3>> abc(pairA, {2,0,0}); 
        if(a & 0b01) abc.back()[0] = 1;
    
        //distribute b and c once for each pass, up to maximal 4 passes
        for(int pass = 0; pass < 4; ++pass) {
            int i = 0;
            for(; i < pairA && b; ++i, --b) ++abc[i][1];
            for(; i < pairA && c; ++i, --c) ++abc[i][2];
        }

        // generate string according to occurrences
        string longest;
        for(auto const& [i, j, k] : abc) { // a^ib^jc^k for each group
            for(int l = 0; l < i; ++l) longest.push_back(letters[0]);
            for(int l = 0; l < j; ++l) longest.push_back(letters[1]);
            for(int l = 0; l < k; ++l) longest.push_back(letters[2]);
            if(!j && !k) break;
        }
        return longest;
    }
};
