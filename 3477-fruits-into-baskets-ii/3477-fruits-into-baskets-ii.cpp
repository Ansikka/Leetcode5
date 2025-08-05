class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();  // Number of fruits
        vector<bool> visited(n, false);  // Vector to track if a basket has been used
        int unplacedFruits = n;  // Initialize the number of unplaced fruits to the total number of fruits

        // Iterate through each fruit
        for (int fruit : fruits) {
            // Attempt to place the fruit into a basket
            for (int i = 0; i < n; ++i) {
                // Check if the basket can hold the fruit and hasn't been used
                if (baskets[i] >= fruit && !visited[i]) {
                    visited[i] = true;  // Mark the basket as used
                    --unplacedFruits;   // Decrease the count of unplaced fruits
                    break;  // Move to the next fruit
                }
            }
        }
        return unplacedFruits; 
    }
};