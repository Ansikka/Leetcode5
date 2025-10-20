class Solution {
public:
  
            int finalValueAfterOperations(vector<string>& operations) {
        // Initialize result variable to track the final value
        int result = 0;
      
        // Iterate through each operation string in the operations vector
        for (const auto& operation : operations) {
            // Check the middle character to determine the operation type
            // If it's '+', increment the result; otherwise decrement it
            // Valid operations: "++X", "X++", "--X", "X--"
            // The middle character (index 1) is always '+' or '-'
            result += (operation[1] == '+') ? 1 : -1;
        }
      
        // Return the final computed value
        return result;

    }
};