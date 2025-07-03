class Solution {
public:
    char kthCharacter(int k) {
          std::vector<int> word;  // Initialize a vector to store the sequence
        word.push_back(0);      // Start with the first character represented by 0
      
        // Continue generating the sequence until it reaches at least k elements
        while (word.size() < k) {
            int currentSize = word.size();  // Current size of the vector
            // Double the sequence by adding 1 modulo 26 to each element
            for (int i = 0; i < currentSize; ++i) {
                word.push_back((word[i] + 1) % 26);
            }
        }
      
        // Return the k-th character, adjust for zero-based indexing
        return 'a' + word[k - 1];
    }
};