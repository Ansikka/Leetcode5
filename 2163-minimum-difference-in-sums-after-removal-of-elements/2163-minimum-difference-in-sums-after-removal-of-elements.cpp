class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
                int m = nums.size(); // Total number of elements in nums
        int n = m / 3; // n is one third the size of the given array nums

        using ll = long long; // Defined for ease of typing long long
        ll sum = 0;
      
        // Array to track the prefix sum
        ll prefixSum[m + 1]; // Sum of the largest `n` numbers up to the current index
      
        // Max heap for managing the largest elements
        priority_queue<int> maxHeap;
        // Calculate the prefix sums for the first `2n` elements
        for (int i = 1; i <= n * 2; ++i) {
            int element = nums[i - 1];
            sum += element;
            maxHeap.push(element);
            // If the heap size exceeds n, pop the maximum element and subtract it from the sum
            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            prefixSum[i] = sum;
        }

        sum = 0;
        // Array to track the suffix sum
        ll suffixSum[m + 1]; // Sum of the smallest `n` numbers starting from the current index

        // Min heap for managing the smallest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        // Calculate the suffix sums for the last `2n` elements
        for (int i = m; i > n; --i) {
            int element = nums[i - 1];
            sum += element;
            minHeap.push(element);
            // If the heap size exceeds n, pop the minimum element and subtract it from the sum
            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            suffixSum[i] = sum;
        }

        // Initialize the answer with a large value
        ll ans = 1e18;
        // Loop through the middle third of nums, comparing prefix and suffix sums
        for (int i = n; i <= n * 2; ++i) {
            // Minimize the answer with the difference between prefix and suffix sums
            ans = min(ans, prefixSum[i] - suffixSum[i + 1]);
        }

        // Return the minimum difference found
        return ans;

    }
};