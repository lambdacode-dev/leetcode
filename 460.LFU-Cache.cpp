class LFUCache {
    //[multiple frequency hashed doubly linked list]
    //(time, space) = O(1) O(N)
    using FreqKeyVal = array<int, 3>;
    map<int/*frequency*/, list<FreqKeyVal>> lists;
    unordered_map<int/*key*/, list<FreqKeyVal>::iterator> dict;
    int capacity;

    int& access(list<FreqKeyVal>::iterator itr) {
        auto [freq, key, val] = *itr;
        lists[freq++].erase(itr);
        lists[freq].push_back({freq, key, val});
        dict[key] = next(lists[freq].rbegin()).base();
        return (*dict[key])[2];
    }
public:
    LFUCache(int capacity) : capacity(capacity) {  }

    int get(int key) {
        auto itr = dict.find(key);
        return itr != dict.end() ? access(itr->second) : -1;
    }

    void put(int key, int value) {
        auto itr = dict.find(key);
        if(itr != dict.end())
            access(itr->second) = value;
        else {
            if(dict.size() == capacity) {
                for(auto & [freq, lst] : lists) {
                   if(!lst.empty()) {
                       auto const& [freq, key, val] = lst.front();
                       dict.erase(key);
                       lst.pop_front();
                       break;
                   }
                }
            }
            if(capacity) {
                lists[1].push_back({1, key, value});
                dict[key] = next(lists[1].rbegin()).base();
            }
        }
    }
};
