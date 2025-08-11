class Solution {
public:
      static constexpr int MOD = 1e9 + 7;

    // This function takes an integer and a set of queries and returns the product of powers for each query
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powersOfTwo;

        // Extract powers of 2 from n and store them in the powersOfTwo vector
        while (n > 0) {
            // Get the rightmost set bit (largest power of 2 not greater than n)
            int largestPowerOfTwo = n & -n;
            // Add the power of 2 to the list
            powersOfTwo.emplace_back(largestPowerOfTwo);
            // Subtract the power of 2 from n to remove that bit
            n -= largestPowerOfTwo;
        }

        vector<int> answer;
        // Iterate through each query
        for (auto& query : queries) {
            int start = query[0], end = query[1];
            long long product = 1;  // Define the product as a long long to prevent integer overflow

            // Calculate the product of powers from start to end index
            for (int i = start; i <= end; ++i) {
                product = (product * powersOfTwo[i]) % MOD;
            }

            // Store the result in answer using modulo to fit within integer range
            answer.emplace_back(static_cast<int>(product));
        }
        // Return the final answers for all queries
        return answer;
    }
};