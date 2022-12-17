class Solution {
    //[two pointers]
    //(time, space) = O(N) O(1)
public:
    int compress(vector<char>& chars) {
        int w = 0; //write pointer
        chars.push_back(0);
        for(int cur = chars[0], cnt = 1, j = 1; j < chars.size(); ++j) {
            if(chars[j] == cur)
                ++cnt;
            else {
                chars[w++] = cur;
                if(cnt > 1) {
                    if(cnt < 10)
                        chars[w++] = '0' + cnt;
                    else
                        w += sprintf(&chars[0] + w, "%d", cnt);
                }
                cur = chars[j];
                cnt = 1;
            }
        }
        return w; 
    }
};
