class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
              int maxEnergy = -(1 << 30);
        int n = energy.size();
      
        // Iterate through all possible ending positions (last k positions)
        // These are the potential starting points for our backward traversal
        for (int endPos = n - k; endPos < n; ++endPos) {
            // For each ending position, traverse backwards with step k
            // and calculate the cumulative sum
            int currentSum = 0;
            for (int currentPos = endPos; currentPos >= 0; currentPos -= k) {
                // Add the energy at current position to the running sum
                currentSum += energy[currentPos];
                // Update the maximum energy if current sum is greater
                maxEnergy = max(maxEnergy, currentSum);
            }
        }
      
        return maxEnergy;
  
    }
};