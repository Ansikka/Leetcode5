class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
              int maxArea = 0;      // Variable to store the maximum area found so far
        int maxDiagonalSq = 0; // Variable to store the square of the maximum diagonal length

        // Loop through the list of dimensions
        for (auto& dimension : dimensions) {
            int length = dimension[0];   // Store the length of the current rectangle
            int width = dimension[1];    // Store the width of the current rectangle
            int diagonalSq = length * length + width * width; // Calculate the square of the diagonal length

            // If the current diagonal is greater than the maximum found so far,
            // update the maximum diagonal and the maximum area accordingly
            if (maxDiagonalSq < diagonalSq) {
                maxDiagonalSq = diagonalSq;
                maxArea = length * width;
            // If the current diagonal equals the maximum diagonal found so far,
            // update the maximum area if the current area is greater
            } else if (maxDiagonalSq == diagonalSq) {
                maxArea = max(maxArea, length * width);
            }
        }

        // Return the maximum area found
        return maxArea;
  
    }
};