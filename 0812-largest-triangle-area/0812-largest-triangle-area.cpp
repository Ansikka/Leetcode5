class Solution {
public:
     double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
      
        // Iterate through all possible combinations of three points
        for (const auto& point1 : points) {
            int x1 = point1[0];
            int y1 = point1[1];
          
            for (const auto& point2 : points) {
                int x2 = point2[0];
                int y2 = point2[1];
              
                for (const auto& point3 : points) {
                    int x3 = point3[0];
                    int y3 = point3[1];
                  
                    // Calculate vectors from point1 to point2 and point1 to point3
                    int vector1X = x2 - x1;
                    int vector1Y = y2 - y1;
                    int vector2X = x3 - x1;
                    int vector2Y = y3 - y1;
                  
                    // Calculate triangle area using cross product formula
                    // Area = |cross product| / 2 = |v1x * v2y - v2x * v1y| / 2
                    double currentArea = abs(vector1X * vector2Y - vector2X * vector1Y) / 2.0;
                  
                    // Update maximum area if current area is larger
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
      
        return maxArea;
    }
};