class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        // Calculate absolute distance from x to z
        int distanceFromX = abs(x - z);
      
        // Calculate absolute distance from y to z
        int distanceFromY = abs(y - z);
      
        // Compare distances and return appropriate result
        if (distanceFromX == distanceFromY) {
            return 0;  // Both are equidistant
        } else if (distanceFromX < distanceFromY) {
            return 1;  // x is closer
        } else {
            return 2;
        }
    }
};