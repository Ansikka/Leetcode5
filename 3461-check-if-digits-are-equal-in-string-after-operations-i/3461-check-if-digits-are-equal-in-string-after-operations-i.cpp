class Solution {
public:
    bool hasSameDigits(string s) {
            int stringLength = s.size();
        string workingString = s;  // Create a copy to modify
      
        // Perform triangular reduction from the end to position 2
        // Each iteration reduces the effective array size by 1
        for (int currentLength = stringLength - 1; currentLength > 1; --currentLength) {
            // For each position up to currentLength, replace the digit
            // with the sum of itself and the next digit (mod 10)
            for (int position = 0; position < currentLength; ++position) {
                // Convert characters to digits, add them, take mod 10, convert back to char
                int currentDigit = workingString[position] - '0';
                int nextDigit = workingString[position + 1] - '0';
                int sumModTen = (currentDigit + nextDigit) % 10;
                workingString[position] = sumModTen + '0';
            }
        }
      
        // After reduction, check if the first two remaining digits are equal
        return workingString[0] == workingString[1];
    }
};