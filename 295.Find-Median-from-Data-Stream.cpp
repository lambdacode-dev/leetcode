class MedianFinder {
    //[stl map]
    //(time, space) = O(logN/1) O(N), where N is size of number set, bounded by 2^32.
    map<int,int> freq;
    map<int,int>::const_iterator mid; // or the first of the two middles if even count
    int offset = 0; // offset within the freq at mid.
    bool even = true;
    void update_median(bool added2right/*of first middle element*/) {
        if( (even = !even) ) {
            if(!added2right) { //inserted to left and now even items: backward middle pointer
                if(!offset)
                    offset = (--mid)->second - 1;
                else
                    --offset;
            }
        }
        else if(added2right) { //inserted to right and now odd: forawrd middle pointer
            if(++offset == mid->second) {
                offset = 0;
                ++mid;
            }
        }
    }
public:
    MedianFinder() { freq[INT_MIN] = 1; mid = freq.begin(); }

    void addNum(int num) {
        auto itr = freq.insert( {num, 0} ).first;
        itr->second++;
        update_median(itr->first >= mid->first);
    }

    double findMedian() {
        return (even && offset + 1 == mid->second) ? (mid->first + next(mid)->first) / 2.0 : mid->first;
    }
};
