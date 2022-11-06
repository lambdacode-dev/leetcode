class LFUCache {
    //[list of list, hashing]: 1st level doubly linked list for same frequency, 2nd level single linked list in asending frequency order
    //(time, space) = O(1) O(N)
    struct KeyVal { int key; int val; };
    using List = list<KeyVal>;// list of values with same frequency
    struct ListAndFreq { list<KeyVal> list; int freq; };
    using LofList = forward_list<ListAndFreq>;

    LofList lofl;
    unordered_map<int, pair<LofList::iterator, List::iterator>> dict;
    int capacity;

    int& access_and_update(int key, LofList::iterator i, List::iterator j) {
        auto I = next(i);
        if( I == lofl.end() || I->freq != i->freq + 1 )
            I = lofl.insert_after( i, {List(), i->freq + 1} );

        auto J = I->list.insert(I->list.end(), {key, j->val} );
        dict[key] = {I, J};

        i->list.erase(j);
        return J->val;
    }
public:
    LFUCache(int capacity) : capacity(capacity) {  }

    int get(int key) {
        auto itr = dict.find(key);
        return itr != dict.end() ? access_and_update(itr->first, itr->second.first, itr->second.second) : -1;
    }

    void put(int key, int value) {
        auto itr = dict.find(key);
        if(itr != dict.end()) {
            access_and_update(itr->first, itr->second.first, itr->second.second) = value;
        }
        else if(capacity) {
            if(dict.size() == capacity) {
                while(lofl.front().list.empty())
                    lofl.pop_front();
                dict.erase(lofl.front().list.front().key);
                lofl.front().list.pop_front();
            }
            if(lofl.empty() || lofl.front().freq != 1)
                lofl.push_front( {List(), 1} );

            dict[key] = { lofl.begin(), lofl.front().list.insert(lofl.front().list.end(), {key, value}) };
        }
    }
};
