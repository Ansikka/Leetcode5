/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    // Function to convert a binary number in a linked list to an integer.
    int getDecimalValue(ListNode* head) {
        int result = 0; // This will hold the decimal value of the binary number

        // Iterate through the linked list
        while (head != nullptr) {
            // Left shift the result by 1 bit to make space for the next bit
            // Then perform a bitwise OR with the current node's value to add the bit to the number
            result = (result << 1) | head->val;

            // Move to the next node
            head = head->next;
        }
        // Return the computed decimal value
        return result;
    }
};