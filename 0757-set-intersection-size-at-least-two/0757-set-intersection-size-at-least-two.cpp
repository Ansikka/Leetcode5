class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
      
        int result = 0;
        // Track the last two points in our intersection set
        // Initialize to invalid values
        int secondLastPoint = -1;
        int lastPoint = -1;
      
        // Process each interval
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
          
            // Case 1: Both tracked points are already in current interval
            // No new points needed
            if (start <= secondLastPoint) {
                continue;
            }
          
            // Case 2: No tracked points are in current interval
            // Need to add 2 new points (choose the rightmost two)
            if (start > lastPoint) {
                result += 2;
                secondLastPoint = end - 1;
                lastPoint = end;
            } 
            // Case 3: Only the last tracked point is in current interval
            // Need to add 1 new point (choose the rightmost)
            else {
                result += 1;
                secondLastPoint = lastPoint;
                lastPoint = end;
            }
        }
      
        return result;
    }
};