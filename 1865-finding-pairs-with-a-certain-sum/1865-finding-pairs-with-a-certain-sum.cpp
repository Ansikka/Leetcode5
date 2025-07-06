
    class FindSumPairs {
public:
    // Constructor initializes the object with two integer vectors
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1; // Assign the first vector to the class member
        this->nums2 = nums2; // Assign the second vector to the class member
      
        // Populate the count map with the frequency of each number in nums2
        for (int value : nums2) {
            ++countMap[value];
        }
    }

    // Function to add a value to an element in nums2 and update the count map
    void add(int index, int value) {
        int oldValue = nums2[index]; // Retrieve the old value from nums2 at the given index
        --countMap[oldValue]; // Decrease the count of the old value in the map
        ++countMap[oldValue + value]; // Increase the count of the new value in the map
        nums2[index] += value; // Update the value in nums2 by adding the given value
    }

    // Function to count the pairs with the given sum 'total'
    int count(int total) {
        int pairsCount = 0; // Initialize the count of valid pairs
      
        // Iterate through elements in nums1 and calculate the complement
        for (int value : nums1) {
            pairsCount += countMap[total - value]; // Add the count of the complement from the map to the pairs count
        }
      
        return pairsCount; // Return the total count of valid pairs
    }

private:
    vector<int> nums1; // First input vector
    vector<int> nums2; // Second input vector
    unordered_map<int, int> countMap; // Map to store the frequency of each number in nums2
};
/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */