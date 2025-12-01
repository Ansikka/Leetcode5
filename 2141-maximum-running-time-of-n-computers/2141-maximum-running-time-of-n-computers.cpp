class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
         long long left = 0, right = 0;
        for (int battery : batteries) {
            right += battery;
        }

        // Binary search for the maximum runtime
        while (left < right) {
            // Calculate mid point (using +1 to avoid infinite loop when left and right are adjacent)
            long long mid = (left + right + 1) >> 1;

            // Calculate total effective capacity at runtime 'mid'
            // Each battery can contribute at most 'mid' units
            long long totalCapacity = 0;
            for (int battery : batteries) {
                totalCapacity += min(static_cast<long long>(battery), mid);
            }

            // Check if we can run n computers for 'mid' time units
            // We need at least n * mid total capacity
            if (totalCapacity >= n * mid) {
                // If possible, try to find a larger runtime
                left = mid;
            } else {
                // If not possible, reduce the runtime
                right = mid - 1;
            }
        }

        // Return the maximum possible runtime
        return left;
    }
};