class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
      
        int n = rains.size();
        vector<int> result(n, -1);  // Initialize result array with -1 (default for rainy days)
      
        // Set to store indices of sunny days (when rains[i] == 0)
        set<int> sunnyDays;
      
        // Map to store the last occurrence index of each lake that got filled
        unordered_map<int, int> lastRainedLakes;
      
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
          
            if (lake > 0) {  // Rainy day - lake gets filled
                // Check if this lake was already filled before
                if (lastRainedLakes.count(lake)) {
                    // Find the first sunny day after the last time this lake was filled
                    auto sunnyDayIt = sunnyDays.upper_bound(lastRainedLakes[lake]);
                  
                    // If no sunny day available to dry this lake, flooding occurs
                    if (sunnyDayIt == sunnyDays.end()) {
                        return {};  // Return empty array indicating failure
                    }
                  
                    // Use this sunny day to dry the current lake
                    result[*sunnyDayIt] = lake;
                    sunnyDays.erase(sunnyDayIt);  // Remove used sunny day
                }
              
                // Update the last occurrence of this lake being filled
                lastRainedLakes[lake] = i;
            } else {  // Sunny day - can dry one lake
                sunnyDays.insert(i);  // Add this sunny day to available days
                result[i] = 1;  // Temporarily set to 1 (can be any valid lake number)
            }
        }
      
        return result;
    }
};