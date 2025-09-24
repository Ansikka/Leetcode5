class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
        // Handle zero numerator case
        if (numerator == 0) {
            return "0";
        }
      
        string result;
      
        // Determine if result should be negative
        // XOR returns true when signs are different
        bool isNegative = (numerator > 0) ^ (denominator > 0);
        if (isNegative) {
            result += "-";
        }
      
        // Convert to long long to avoid overflow when taking absolute values
        long long dividend = abs(static_cast<long long>(numerator));
        long long divisor = abs(static_cast<long long>(denominator));
      
        // Add the integer part
        result += to_string(dividend / divisor);
      
        // Calculate remainder
        dividend %= divisor;
      
        // If no remainder, we have a terminating decimal
        if (dividend == 0) {
            return result;
        }
      
        // Add decimal point for fractional part
        result += ".";
      
        // Map to store remainder positions for detecting repeating patterns
        // Key: remainder value, Value: position in result string
        unordered_map<long long, int> remainderToPosition;
      
        // Process the fractional part
        while (dividend != 0) {
            // Record current remainder and its position in result
            remainderToPosition[dividend] = result.size();
          
            // Multiply remainder by 10 for next digit calculation
            dividend *= 10;
          
            // Append next digit to result
            result += to_string(dividend / divisor);
          
            // Update remainder for next iteration
            dividend %= divisor;
          
            // Check if we've seen this remainder before (indicates repeating pattern)
            if (remainderToPosition.count(dividend)) {
                // Insert opening parenthesis at the start of repeating sequence
                result.insert(remainderToPosition[dividend], "(");
                // Add closing parenthesis at the end
                result += ")";
                break;
            }
        }
      
        return result;
    }
};