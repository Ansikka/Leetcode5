class Solution {
public:

 string findLexSmallestString(string s, int a, int b) {
        // Use BFS to explore all possible string transformations
        queue<string> bfsQueue{{s}};
        unordered_set<string> visited{{s}};
        string minString = s;
        int stringLength = s.size();
      
        while (!bfsQueue.empty()) {
            string currentString = bfsQueue.front();
            bfsQueue.pop();
          
            // Update the lexicographically smallest string found so far
            minString = min(minString, currentString);
          
            // Operation 1: Add 'a' to all odd-indexed characters
            string addResult = currentString;
            for (int i = 1; i < stringLength; i += 2) {
                // Convert char to digit, add 'a', apply modulo 10, convert back to char
                addResult[i] = (addResult[i] - '0' + a) % 10 + '0';
            }
          
            // Operation 2: Rotate string to the right by 'b' positions
            // Take last 'b' characters and concatenate with first 'n-b' characters
            string rotateResult = currentString.substr(stringLength - b) + 
                                  currentString.substr(0, stringLength - b);
          
            // Process both transformed strings
            for (const auto& transformedString : {addResult, rotateResult}) {
                // If this string hasn't been visited, add it to the queue
                if (!visited.count(transformedString)) {
                    visited.insert(transformedString);
                    bfsQueue.emplace(transformedString);
                }
            }
        }
      
        return minString;
    }
};