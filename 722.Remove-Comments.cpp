//[linear scan with block comment state update]
//(time, space) = O(N), O(N)
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> code;   
        for(int i = 0, inblock = 0, wasinblock = 0; i < source.size(); ++i) {
            string line = source[i];
            if(inblock) {
                if(auto pos = line.find("*/"); pos != string::npos) {
                    line = line.substr(pos+2);
                    inblock = !(wasinblock = true);
                    source[i--] = line;
                }
            }
            else {
                auto pos1 = line.find("/*"), pos2 = line.find("//");
                if(pos1 == string::npos) pos1 = line.size();
                if(pos2 == string::npos) pos2 = line.size();
                if(pos1 != pos2) {
                    inblock = (pos1 < pos2);
                    line = line.substr(0, std::min(pos1, pos2));
                }
                if(wasinblock) {
                    line = code.back() + line;
                    code.pop_back();
                    wasinblock = false;
                } 
                if(inblock || !line.empty()) {
                    code.push_back(line);
                }
                if(inblock) {
                    line = source[i].substr(pos1+2);
                    source[i--] = line;
                }
            }
        }
        return code;
    }
};
