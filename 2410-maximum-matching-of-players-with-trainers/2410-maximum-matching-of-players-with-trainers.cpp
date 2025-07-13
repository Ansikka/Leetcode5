class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
           std::sort(players.begin(), players.end()); // Sort the players in ascending order
        std::sort(trainers.begin(), trainers.end()); // Sort the trainers in ascending order

        int matches = 0; // Initialize the number of matches to zero
        int trainersIndex = 0; // Initialize the trainers index to the start of the array

        // Iterate through each player
        for (int playerStrength : players) {
            // Find a trainer that can match the current player's strength
            while (trainersIndex < trainers.size() && trainers[trainersIndex] < playerStrength) {
                trainersIndex++; // Increment trainers index if the current trainer is weaker than the player
            }

            // If a suitable trainer is found, make the match
            if (trainersIndex < trainers.size()) {
                matches++; // Increment match count
                trainersIndex++; // Move to the next trainer for the following players
            }
        }

        return matches; 
    }
};