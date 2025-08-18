class Solution {
public:
  

      bool judgePoint24(std::vector<int>& nums) {
        // Convert the input array of integers to a vector of doubles.
        std::vector<double> numList(nums.begin(), nums.end());
        // Initiate depth-first search to evaluate all possible results.
        return dfs(numList);
    }

private:
    // Recursive method to perform depth-first search.
    bool dfs(std::vector<double>& numList) {
        // If there are no numbers, we cannot perform any operations; return false.
        if (numList.empty()) {
            return false;
        }
        // If there is only one number left, check if it's approximately 24.
        if (numList.size() == 1) {
            return std::abs(numList[0] - 24.0) < 1e-6;
        }
        // Try all pairs of numbers with all operations.
        for (int i = 0; i < numList.size(); ++i) {
            for (int j = i + 1; j < numList.size(); ++j) {
                // Check if the result of any operation on these two numbers
                // combined with the remaining numbers can result in 24.
                for (int operation = 0; operation < 6; ++operation) {
                    std::vector<double> nextList = getNextList(numList, i, j, operation);
                    if (!nextList.empty() && dfs(nextList)) {
                        return true;
                    }
                }
            }
        }
        // If no combination resulted in 24, return false.
        return false;
    }

    // Method to create a new list by applying an operation to a pair of numbers.
    std::vector<double> getNextList(std::vector<double>& numList, int firstIndex, int secondIndex, int operation) {
        std::vector<double> nextNumList;
        // Add all numbers except the pair we're operating on.
        for (int k = 0; k < numList.size(); ++k) {
            if (k != firstIndex && k != secondIndex) {
                nextNumList.push_back(numList[k]);
            }
        }

        // Perform the operation based on the operation index.
        double firstNumber = numList[firstIndex];
        double secondNumber = numList[secondIndex];

        switch (operation) {
            case 0: // Addition
                nextNumList.push_back(firstNumber + secondNumber);
                break;
            case 1: // Subtraction (first - second)
                nextNumList.push_back(firstNumber - secondNumber);
                break;
            case 2: // Subtraction (second - first)
                nextNumList.push_back(secondNumber - firstNumber);
                break;
            case 3: // Multiplication
                nextNumList.push_back(firstNumber * secondNumber);
                break;
            case 4: // Division (first / second), check for division by zero.
                if (std::abs(secondNumber) < 1e-6) {
                    return {};
                }
                nextNumList.push_back(firstNumber / secondNumber);
                break;
            case 5: // Division (second / first), check for division by zero.
                if (std::abs(firstNumber) < 1e-6) {
                    return {};
                }
                nextNumList.push_back(secondNumber / firstNumber);
                break;
        }

        // Return the new list of numbers to continue the search.
        return nextNumList;

    }
};