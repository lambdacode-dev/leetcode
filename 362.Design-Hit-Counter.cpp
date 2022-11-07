class HitCounter {
    //[queue of hit time and occurrence pair] : scalable on huge events of same hit time
    //(time, space) = O(1) O(N)
    constexpr static int time = 0;
    constexpr static int freq = 1;
    queue<array<int,2>> Q;// strictly increasing on time with hit count at the time
    int count = 0; // total hit count

    void purgeOldHits(int timestamp) {
        int mintime = timestamp - 300 + 1;
        while(!Q.empty() && mintime > Q.front()[time]) {
            count -= Q.front()[freq];
            Q.pop();
        }
    }
public:
    HitCounter() {}

    void hit(int timestamp) {
        if(!Q.empty() && timestamp == Q.back()[time]) {
            Q.back()[freq]++;
            count++;
        }
        else {
            purgeOldHits(timestamp);
            Q.push( {timestamp, 1} );
            count++;
        }
    }

    int getHits(int timestamp) {
        if(!Q.empty() && timestamp > Q.back()[time])
            purgeOldHits(timestamp);
        return count;
    }
};
