class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
      int maxFruits = 0; // Store the maximum total fruits that can be collected.
        int currentSum = 0; // Store the current sum of fruits being considered.

        // Use a sliding window defined by the indices [i, j].
        for (int i = 0, j = 0; j < fruits.size(); ++j) {
            int positionJ = fruits[j][0]; // Position of the j-th fruit tree
            int fruitCountJ = fruits[j][1]; // Number of fruits at the j-th fruit tree
            currentSum += fruitCountJ; // Add the fruits from the j-th tree to the current sum

          
            while (i <= j && positionJ - fruits[i][0] + 
                   min(abs(startPos - fruits[i][0]), abs(startPos - positionJ)) > k) {
                currentSum -= fruits[i][1]; // Remove the fruits from the i-th tree from the current sum
                i++; // Move the start of the window to the right
            }

            
            maxFruits = max(maxFruits, currentSum);
        }

        return maxFruits;   
    }
};