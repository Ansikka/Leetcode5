class FoodRatings {
public:
     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        // Initialize the food rating system with the given arrays
        for (int i = 0; i < foods.size(); ++i) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
          
            // Store food-rating pairs for each cuisine in a sorted set
            // Use negative rating for descending order, food name for lexicographic tiebreaker
            cuisineToFoodSet[cuisine].insert({-rating, food});
          
            // Store the rating and cuisine for each food for quick lookup
            foodInfo[food] = {rating, cuisine};
        }
    }
  
    void changeRating(string food, int newRating) {
        // Retrieve the current rating and cuisine of the food
        auto [oldRating, cuisine] = foodInfo[food];
      
        // Update the food's rating in the lookup map
        foodInfo[food] = {newRating, cuisine};
      
        // Remove the old entry from the cuisine's sorted set
        cuisineToFoodSet[cuisine].erase({-oldRating, food});
      
        // Insert the new entry with updated rating
        cuisineToFoodSet[cuisine].insert({-newRating, food});
    }
  
    string highestRated(string cuisine) {
        // Return the food with highest rating for the given cuisine
        // The set is sorted by rating (descending) and food name (ascending)
        return cuisineToFoodSet[cuisine].begin()->second;
    }
  
private:
    // Map from cuisine to a set of (negative rating, food name) pairs
    // Set automatically maintains sorted order: highest rating first, then lexicographically
    unordered_map<string, set<pair<int, string>>> cuisineToFoodSet;
  
    // Map from food name to its (rating, cuisine) information
    unordered_map<string, pair<int, string>> foodInfo;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */