//[in place swap]
//(time, space) = O(N) O(1)
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for(int i = 0, j = indices[i]; i < indices.size();) {
            if(i == j) {
                for(++i; i < indices.size() && indices[i] == -1; ++i);
                if(i < indices.size())
                    j = indices[i];
            }
            else {// move s[i] to pos j, and save [j] temporarily to pos i
                swap(s[i], s[j]);
                auto j0 = j;
                j = indices[j];
                indices[j0] = -1;
            }
        }
        return s;
    }
};
