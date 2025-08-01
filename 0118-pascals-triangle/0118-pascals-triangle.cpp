class Solution {
public:
    vector<vector<int>> generate(int numRows) {
            vector<vector<int>> pascalsTriangle;

        // The first row of Pascal's Triangle is always [1].
        pascalsTriangle.push_back(vector<int>(1, 1));

        // Generate the subsequent rows of Pascal's Triangle.
        for (int rowIndex = 1; rowIndex < numRows; ++rowIndex) {
            // Initialize the new row starting with a '1'.
            vector<int> newRow;
            newRow.push_back(1);

            // Fill in the values between the first and last '1' of the row.
            for (int elementIndex = 0; elementIndex < pascalsTriangle[rowIndex - 1].size() - 1; ++elementIndex) {
                // The new value is the sum of the two values directly above it.
                newRow.push_back(pascalsTriangle[rowIndex - 1][elementIndex] + pascalsTriangle[rowIndex - 1][elementIndex + 1]);
            }

            // The last value in a row of Pascal's Triangle is always '1'.
            newRow.push_back(1);

            // Append the newly created row to Pascal's Triangle.
            pascalsTriangle.push_back(newRow);
        }
      
        // Return the fully generated Pascal's Triangle.
        return pascalsTriangle; 
    }
};