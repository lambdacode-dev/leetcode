class Solution {
    //[dijkstra]
    //(time, space) = O(N+ElogE), O(N+E)
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, unordered_map<int,int>> adj; // adj[a][b]=t, time t from node a to b
        for(auto const& abt : times)
            adj[abt[0]][abt[1]] = abt[2];
        struct Node {
            int delay, node;
            bool operator<(Node const& that) const { return delay > that.delay; }
        };
        priority_queue<Node> heap;
        vector<int> node2delay(n+1, INT_MAX); // from source node k
        heap.push( {0, k} );
        while(!heap.empty()) {
            auto [delay, node] = heap.top();
            heap.pop();
            if(delay > node2delay[node]) 
                continue; //dirty heap node
            node2delay[node] = delay;
            for(auto const& [n, t] : adj[node]) {
                if(delay + t < node2delay[n]) 
                    heap.push( {delay + t, n} );
            }
        }
        int time = 0;
        for(int i = 1; i <= n; ++i) {
            if(node2delay[i] > time)
                time = node2delay[i];
        }
        return time== INT_MAX ? -1 : time;
    }
};
