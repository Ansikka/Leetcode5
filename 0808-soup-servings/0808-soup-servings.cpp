class Solution {
public:
   
       double soupServings(int n) {
        // Cache probability results to avoid redundant calculations
        double probabilityCache[200][200] = {0.0};
      
        // Recursive function to calculate probabilities using memorization
        function<double(int, int)> calculateProbabilities = [&](int soupA, int soupB) -> double {
            // Base cases when either or both soup quantities become non-positive
            if (soupA <= 0 && soupB <= 0) return 0.5; 
            if (soupA <= 0) return 1;
            if (soupB <= 0) return 0;
            // Return the cached result if it has already been computed
            if (probabilityCache[soupA][soupB] > 0) return probabilityCache[soupA][soupB];
          
            // Recursive case: calculate the probability and cache it
            double probability = 0.25 * (calculateProbabilities(soupA - 4, soupB) + 
                                         calculateProbabilities(soupA - 3, soupB - 1) +
                                         calculateProbabilities(soupA - 2, soupB - 2) + 
                                         calculateProbabilities(soupA - 1, soupB - 3));
            probabilityCache[soupA][soupB] = probability;
            return probability;
        };
      
        // According to problem description, for large 'n' values, probability converges to 1
        // The value 4800 is determined empirically; for inputs larger than this, return 1
        if (n > 4800) {
            return 1;
        }
      
        // For smaller values of 'n', use the recursive function to calculate the probability,
        // normalizing 'n' so that the maximum index does not exceed 200.
        return calculateProbabilities((n + 24) / 25, (n + 24) / 25);

    }
};