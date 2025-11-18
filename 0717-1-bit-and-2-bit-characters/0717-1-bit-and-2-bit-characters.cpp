class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
          // Initialize pointer and get array size
        int i = 0;
        int n = bits.size();
      
        // Traverse through the bits array until we reach or pass the second-to-last position
        // If current bit is 0: it's a 1-bit character, move forward by 1 (0 + 1)
        // If current bit is 1: it's a 2-bit character, move forward by 2 (1 + 1)
        while (i < n - 1) {
            i += bits[i] + 1;
        }
      
        // If we landed exactly on the last position (n-1), 
        // it means the last character is a 1-bit character
        return i == n - 1;
    }
};