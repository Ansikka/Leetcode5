#include <vector>
#include <unordered_set>

class Solution {
public:
    // Function to count the number of distinct bitwise OR values of all subarrays.
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> uniqueOrValues;  // To store unique OR values of subarrays.
        int currentOr = 0;                  // To store the running OR value of the current subarray.
      
        // Iterate over each element in the array.
        for (int i = 0; i < arr.size(); ++i) {
            currentOr |= arr[i];            // Update the running OR with the current element.
            int subarrayOr = 0;             // Used to calculate OR for each possible subarray ending at 'i'.
          
            // Iterate from the current element to the beginning of the array.
            for (int j = i; j >= 0; --j) {
                subarrayOr |= arr[j];        // Update the OR for the subarray ending at 'i' starting at 'j'.
                uniqueOrValues.insert(subarrayOr);  // Store the calculated OR in the set.
              
                // Break the loop if the subarray OR equals the currently calculated OR (all bits already set).
                if (subarrayOr == currentOr) break;
            }
        }
      
        // The size of the set represents the number of distinct OR values of all subarrays.
        return uniqueOrValues.size();
    }
};