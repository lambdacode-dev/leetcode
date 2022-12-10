//[maintain/update pointer to next chunk]
//(time, space) = O(1) amortized
class OrderedStream {
    vector<string> data;
    int i = 1;
public:
    OrderedStream(int n) {
        data.resize(n+2); 
    }
    
    vector<string> insert(int idKey, string value) {
        data[idKey] = value;
        vector<string> chunk;
        while( !data[i].empty() )
            chunk.push_back(data[i++]);
        return chunk;
    }
}
