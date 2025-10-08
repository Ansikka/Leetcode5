class Solution {
public:
       vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
     
        sort(potions.begin(), potions.end());
      
        
        vector<int> result;
      
        
        int potionCount = potions.size();
      
        // Iterate through each spell
        for (int& spellStrength : spells) {
            
            long long minPotionStrength = (success + spellStrength - 1) / spellStrength;
          
           
            int firstValidIndex = lower_bound(potions.begin(), potions.end(), minPotionStrength) - potions.begin();
          
           
            int successfulPairCount = potionCount - firstValidIndex;
          
            // Add the count to result vector
            result.push_back(successfulPairCount);
        }
      
        return result;
    }
};