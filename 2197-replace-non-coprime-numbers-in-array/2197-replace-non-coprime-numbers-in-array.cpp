class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
         
        vector<int> stack;
      
        // Process each number in the input array
        for (int currentNum : nums) {
            // Add current number to the stack
            stack.push_back(currentNum);
          
            // Keep merging adjacent non-coprime numbers until no more merges are possible
            while (stack.size() > 1) {
                // Get the last two elements from the stack
                int topElement = stack.back();
                int secondElement = stack[stack.size() - 2];
              
                // Calculate the greatest common divisor
                int gcd = __gcd(topElement, secondElement);
              
                // If the two numbers are coprime (GCD = 1), stop merging
                if (gcd == 1) {
                    break;
                }
              
                // Remove the top element
                stack.pop_back();
              
                // Replace the second element with LCM of the two numbers
                // LCM(a, b) = (a * b) / GCD(a, b)
                // Using 1LL to prevent integer overflow during multiplication
                stack.back() = 1LL * topElement * secondElement / gcd;
            }
        }
      
        return stack;
    }
};