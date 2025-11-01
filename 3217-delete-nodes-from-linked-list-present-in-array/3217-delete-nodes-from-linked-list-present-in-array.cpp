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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
         unordered_set<int> numsSet(nums.begin(), nums.end());
      
       
        ListNode* dummyNode = new ListNode(0, head);
      
        // Iterate through the linked list using a previous pointer
        for (ListNode* prevNode = dummyNode; prevNode->next != nullptr;) {
            // Check if the next node's value exists in the set
            if (numsSet.count(prevNode->next->val)) {
                // Remove the next node by updating the pointer
                prevNode->next = prevNode->next->next;
                // Note: prevNode stays at the same position for the next iteration
            } else {
                // Move to the next node only if no deletion occurred
                prevNode = prevNode->next;
            }
        }
      
        // Return the modified list (head might have changed)
        return dummyNode->next;
    }
};