class Solution {
    //[parse to build strings for comparison]
    //(time, space) = O(N) O(N) where N is total string length
public:
    bool backspaceCompare(string s, string t) {
        auto parse = [] (string const& s) {
            string a;
            for(auto c : s) {
                if(c != '#')
                    a.push_back(c);
                else if(!a.empty())
                    a.pop_back();
            }
            return a;
        };
        return parse(s) == parse(t);
    }
};
