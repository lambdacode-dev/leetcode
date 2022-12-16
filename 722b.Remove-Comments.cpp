//[C++ regex]
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string src = accumulate(source.begin(), source.end(), string{}, [](auto const& a, auto const& b) { return a+b+"\n"; });
        string shortestblockcomment = "/\\*"  "(.|\\n)*?"  "\\*/";
        string linecomment = "//.*";
        regex comment("(" + shortestblockcomment + ")|(" + linecomment + ")");
        src = std::regex_replace(src, comment, "");
        istringstream f(src);
        source.clear();
        for(string line; getline(f, line); ) {
            if(!line.empty())
                source.push_back(line);
        }
        return source;
    }
}
