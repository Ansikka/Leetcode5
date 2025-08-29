class Solution {
public:
    
     long long flowerGame(int n, int m) {
        // Calculate half of the length of the garden rounded up
        long long length_rounded_up = (n + 1) / 2;
        // Calculate half of the width of the garden rounded up
        long long width_rounded_up = (m + 1) / 2;

        // Calculate half of the length of the garden rounded down
        long long length_rounded_down = n / 2;
        // Calculate half of the width of the garden rounded down
        long long width_rounded_down = m / 2;

        long long total_pairs = length_rounded_up * width_rounded_down + length_rounded_down * width_rounded_up;

   
        return total_pairs;
    }
};