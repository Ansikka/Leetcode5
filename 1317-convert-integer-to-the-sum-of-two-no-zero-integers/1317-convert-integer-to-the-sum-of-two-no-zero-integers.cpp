class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
        // Iterate through all possible values of the first integer starting from 1
        for (int firstNum = 1; ; ++firstNum) {
            // Calculate the second integer such that their sum equals n
            int secondNum = n - firstNum;
          
            // Convert both integers to strings and concatenate them
            string combinedStr = to_string(firstNum) + to_string(secondNum);
          
            // Check if the concatenated string contains the digit '0'
            // string::npos is returned when '0' is not found
            if (combinedStr.find('0') == string::npos) {
                // If no '0' is found in either number, return the pair
                return {firstNum, secondNum};
            }
        }
    }
};