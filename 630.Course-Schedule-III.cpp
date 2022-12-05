class Solution {
    //courses can be sorted in monotonically increasing last day order without loss of generality to the solution
    //[priority queue]: to keep max duration of scheduled courses, and possibly swap with next course.
    //(time, space) = O(NlogN) O(N)
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto const& a, auto const& b) { return a[1] < b[1]; });
        priority_queue<int> heap;
        for(int totaltime = 0, i = 0; i < courses.size(); ++i) {
            auto duration = courses[i][0];
            if(totaltime + duration <= courses[i][1]) {
                totaltime += duration;
                heap.push(duration);
            }
            else if(!heap.empty() && duration < heap.top()) {
                totaltime += duration - heap.top();
                heap.pop();
                heap.push(duration);
            }
        }
        return heap.size();
    }
};
