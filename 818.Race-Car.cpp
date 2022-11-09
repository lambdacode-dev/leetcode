class Solution {
public:
    //[dijkstra algorithm]: acceleration moves A^iR of displacement = 2^i - 1, with i+1 steps/dist as edge cost
    //(time, space) = O(NlogN) O(N) where N = target
    //<Critical observations>: 
    // (1) optimal moves are (A^iR)+, where A^iR is edge of node which is current position. (last R will be removed) 
    // (2) flip x dir to align with that of speed. pos/negative position: move away/toward 0
    // (3) start at x = +target (moving away from 0, so next,i.e. first, move will be toward 0)
    
    int racecar(int target) {
        int A[15]; //max target 10e4 = 10k, A[14] = 16k is the bound for optimal moves
        for(int i = 0; i < 15; ++i) A[i] = (0b01 << i) - 1;
        int N = lower_bound(A, A+15, target) - A;
        
        struct Node {
            int d, p; //distance function value of d at node of position p
            bool operator<(Node const& that) const { return d > that.d; }
        };
        priority_queue<Node> minheap;
        minheap.push( {0, target} );
        
        vector<int> dist(2*A[N]+1, INT_MAX);
        dist[target + A[N]] = 0;
        
        for(int d, p; ! minheap.empty() && (p = minheap.top().p); ) {
            d = minheap.top().d;
            minheap.pop();
            if(d > dist[p + A[N]])
                continue; //skip dirty node
            
            for(int i = 0; i <= N; ++i) {
                auto d2 = d + i + 1;
                auto p2 = -p + A[i];
                if( abs(p2) <= A[N] && d2 < dist[p2+A[N]] ) {
                    dist[p2+A[N]] = d2;
                    minheap.push( { d2, p2 } );
                }
            }
        }
        return dist[A[N]] - 1; // -1 to remove the last R move
    }
};
