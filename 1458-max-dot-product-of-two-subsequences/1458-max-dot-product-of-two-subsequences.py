class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
      
        # Initialize DP table with negative infinity
        # dp[i][j] represents the maximum dot product using first i elements from nums1
        # and first j elements from nums2
        dp = [[float('-inf')] * (n + 1) for _ in range(m + 1)]
      
        # Iterate through each element in nums1
        for i in range(1, m + 1):
            # Iterate through each element in nums2
            for j in range(1, n + 1):
                # Calculate the product of current elements
                current_product = nums1[i - 1] * nums2[j - 1]
              
                # Take maximum of three cases:
                # 1. Skip current element from nums1: dp[i-1][j]
                # 2. Skip current element from nums2: dp[i][j-1]
                # 3. Include current pair: max(0, dp[i-1][j-1]) + current_product
                #    (we take max with 0 to optionally start a new subsequence)
                dp[i][j] = max(
                    dp[i - 1][j],                                    # Skip nums1[i-1]
                    dp[i][j - 1],                                    # Skip nums2[j-1]
                    max(0, dp[i - 1][j - 1]) + current_product      # Include both elements
                )
      
        # Return the maximum dot product using all available elements
        return dp[m][n]
