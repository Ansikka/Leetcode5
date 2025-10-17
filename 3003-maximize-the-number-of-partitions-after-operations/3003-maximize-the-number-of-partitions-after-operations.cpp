class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
         int n = s.size();
        // Memoization map: key = (index << 32) | (charMask << 1) | canChange
        unordered_map<long long, int> memo;
      
        // DFS function to find maximum partitions
        // Parameters:
        // - index: current position in string
        // - charMask: bitmask representing distinct characters in current partition
        // - canChange: flag indicating if we can still change one character (1 = yes, 0 = no)
        function<int(int, int, int)> dfs = [&](int index, int charMask, int canChange) {
            // Base case: reached end of string, count last partition
            if (index >= n) {
                return 1;
            }
          
            // Create unique key for memoization
            long long stateKey = (long long)index << 32 | charMask << 1 | canChange;
          
            // Return memoized result if exists
            if (memo.count(stateKey)) {
                return memo[stateKey];
            }
          
            // Get bitmask for current character
            int currentCharBit = 1 << (s[index] - 'a');
          
            // Calculate new character mask if we add current character
            int newCharMask = charMask | currentCharBit;
          
            // Calculate result without changing current character
            int maxPartitions;
            if (__builtin_popcount(newCharMask) > k) {
                // Too many distinct characters, start new partition
                maxPartitions = dfs(index + 1, currentCharBit, canChange) + 1;
            } else {
                // Continue with current partition
                maxPartitions = dfs(index + 1, newCharMask, canChange);
            }
          
            // Try changing current character if we still have the option
            if (canChange) {
                // Try replacing current character with each letter 'a' to 'z'
                for (int letter = 0; letter < 26; ++letter) {
                    int replacementCharBit = 1 << letter;
                    newCharMask = charMask | replacementCharBit;
                  
                    if (__builtin_popcount(newCharMask) > k) {
                        // Too many distinct characters, start new partition
                        maxPartitions = max(maxPartitions, 
                                          dfs(index + 1, replacementCharBit, 0) + 1);
                    } else {
                        // Continue with current partition
                        maxPartitions = max(maxPartitions, 
                                          dfs(index + 1, newCharMask, 0));
                    }
                }
            }
          
            // Memoize and return result
            return memo[stateKey] = maxPartitions;
        };
      
        // Start DFS from index 0, empty character mask, with ability to change one character
        return dfs(0, 0, 1);
    }
};