class MedianFinder {
    //[stl multiset]
    //(time, space) = O(logN) O(1) O(N) 
    multiset<int> nums;
    multiset<int>::const_iterator itrl, itrr; // the two mid eles iterators 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto itr = nums.insert(num);
        if(nums.size() == 1)
            itrl = itrr = itr;
        else if(*itr < *itrl) // inserted to left half
        {
            if(itrl == itrr)   // prev odd sz
                --itrl;
            else
                itrr = itrl;
        }
        else if(*itr >= *itrr) // inserted to right half
        {
            if(itrl == itrr)
                ++itrr;
            else
                itrl = itrr;
        }
        else
            itrl = itrr = itr;
    }
    
    double findMedian() {
        if(nums.empty()) return 0.0;
        return (*itrl + *itrr) / 2.0;
    }
};
