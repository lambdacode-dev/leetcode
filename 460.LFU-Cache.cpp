class LFUCache {
    //[hash, heap]: for storing cache, and for cache eviction 
    //heap of (freq, clock, key): min on freq, min on clock: need clock to mark dirty heap node
    //(time,space) = O(1) O(N)
    struct HeapNode {
        int key = 0;
        int freq = 0;
        int clock = 0;
        bool operator<(HeapNode const& that) const {
            return freq != that.freq ? freq > that.freq : clock > that.clock; 
        }
    };
    priority_queue<HeapNode> pq;
    
    struct MapNode {
        int val = 0;
        int freq = 0;
        int clock = 0;
    };
    unordered_map<int,MapNode> hash;
    
    int clock = 0;
    int capacity;
    
    void update_access(int key, MapNode& node) 
    {
        pq.push( { key, ++node.freq, (node.clock = ++clock) } );
    }
public:
    LFUCache(int capacity) : capacity(capacity) {  }
    
    int get(int key) {
        auto itr = hash.find(key);
        if(itr == hash.end()) 
            return -1;
        
        update_access(key, itr->second);
        return itr->second.val;
            
    }
    
    void put(int key, int val) {
        auto itr = hash.find(key);
        if(itr != hash.end()) 
        {
            itr->second.val = val;
            update_access(key, itr->second);
        }
        else
        {
            while(hash.size() == capacity && !pq.empty())
            {
                auto const& node = pq.top();
                auto itr = hash.find(node.key);
                if(itr != hash.end() && itr->second.clock == node.clock) // otherwise dirty heap node
                    hash.erase(node.key);
                pq.pop();
            }
            if(capacity)
            {
                auto& node = (hash[key] = {val});
                update_access(key, node);
            }
        }
    }
};
