class Solution {
    //[backtracking]: addition directly on string of digits
    //(time, space) = O(N^3) O(N)
public:
    bool isAdditiveNumber(string num) {
        auto additive_triple = [&num](int i, int j, int k, int l) {//[i,j) + [j, k) == [k,l) ?
            if(l > num.size() || (num[i] == '0' && j-i > 1) || (num[j] == '0' && k-j > 1) || (num[k] == '0' && l-k > 1)) 
                return false;
            
            int carry = 0;
            for(auto a = j - 1, b = k - 1, c = l - 1; c >= k; --a, --b, --c) {
                int n = (a >= i ? num[a] - '0' : 0) + (b >= j ? num[b] - '0' : 0) + carry;
                carry = n / 10;
                n = n % 10;
                if(n != num[c] - '0') 
                    return false;
            }
            return !carry;
        };
        
        function<bool(int, int, int, int)> additive_seq;
        additive_seq = [&num, &additive_seq, &additive_triple] (int i, int asz, int bsz, int csz) {
            if(additive_triple(i, i+asz, i+asz+bsz, i+asz+bsz+csz)) {
                if(i+asz+bsz+csz == num.size())
                    return true;
                return additive_seq(i+asz, bsz, csz, csz) || additive_seq(i+asz, bsz, csz, csz+1); 
            }
            return false;
        };
        
        for(int asz = num.size() / 2; asz; --asz) {
            for(int bsz = num.size() / 2; bsz; --bsz) {
                for(int csz = max(asz, bsz), pass = 0; pass < 2; ++pass, ++csz) {
                    if(additive_seq(0, asz, bsz, csz))
                        return true;
                }
            }
        }
        return false;
    }
};
