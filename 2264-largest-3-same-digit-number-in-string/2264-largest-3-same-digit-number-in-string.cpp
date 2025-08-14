class Solution {
public:
    string largestGoodInteger(string num) {
        for (char digit = '9'; digit >= '0'; --digit) {
            // Create a string consisting of three identical characters (digits)
            string triplet(3, digit);

            // If the triplet is found in 'num', return it as it's the largest "good" integer
            if (num.find(triplet) != string::npos) {
                // Return the first instance of the largest "good" integer found
                return triplet;
            }
        }
        // If no triplet found, return an empty string
        return "";
    }
};