class Solution {
    //courses can be sorted in monotonically increasing last day order without loss of generality to the solution
    //[priority queue]: to keep max duration of scheduled courses, and possibly swap with next course.
    //(time, space) = O(NlogN) O(N)
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto const& a, auto const& b) { return a[1] < b[1]; });
        priority_queue<int> heap;
        for(int time = 0, i = 0; i < courses.size(); ++i) {
            heap.push(courses[i][0]);
            if( (time += courses[i][0]) > courses[i][1]) {
                time -= heap.top();
                heap.pop();
            }
        }
        return heap.size();
    }
};
