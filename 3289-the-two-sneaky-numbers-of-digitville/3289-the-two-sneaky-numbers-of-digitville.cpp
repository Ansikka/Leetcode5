class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
                // Result vector to store numbers that appear exactly twice
        vector<int> result;
      
        // Frequency array to count occurrences of each number (0-99)
        int frequency[100] = {0};
      
        // Iterate through all numbers in the input array
        for (int number : nums) {
            // Increment the count for current number
            frequency[number]++;
          
            // If this number appears exactly twice, add it to result
            if (frequency[number] == 2) {
                result.push_back(number);
            }
        }
      
        return result;
    }
};