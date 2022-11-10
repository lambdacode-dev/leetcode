class Solution {
    //[stack and update on stack top]
    //(time, space) = O(N) O(N) where N is decoded string size
public:
    string decodeString(string s) {
        string decoded;
        stack<pair<int, string>> stack;
        stack.push({1, ""});
        for(int i = 0; i < s.size(); ++i) {
            if(isdigit(s[i])) {
                int k = s[i] - '0';
                while(isdigit(s[++i])) k = 10*k + (s[i] - '0');
                stack.push( {k, ""} );
            }
            else if(s[i] == ']') {
                auto [k, str] = stack.top();
                stack.pop();
                for(int i = 0; i < k; ++i)
                    stack.top().second += str;
            }
            else // regular lower case letter 
                stack.top().second.push_back(s[i]);
        }
        return stack.top().second;
    }
};
