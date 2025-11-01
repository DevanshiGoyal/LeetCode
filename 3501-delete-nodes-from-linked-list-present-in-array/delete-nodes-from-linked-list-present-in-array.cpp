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
        // using hashset
        //we can check in O(1) time if a value needs removal 
        //o(m)
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        /// Handle the case where the head node needs to be removed
        while (head != nullptr && valuesToRemove.count(head->val) > 0) {
            ListNode* temp = head;
            head = head->next;
            //delete temp;
        }

        // If the list is empty after removing head nodes, return nullptr
        if (head == nullptr) {
            return nullptr;
        }
        // Iterate through the list, removing nodes with values in the set
        //O(n)
        ListNode* current = head;
        while (current->next != nullptr) {
            if (valuesToRemove.contains(current->next->val)) {
                // Store the node to be deleted
                ListNode* temp = current->next;
                // Skip the next node by updating the pointer
                current->next = current->next->next;
                // Delete the removed node
                //delete temp; ---> giving runtime error --> no  manual deletion ---> backend 
            } else {
                // Move to the next node
                current = current->next;
            }
        }

        return head;


    }
};

// TC--->O(m+n)
//O(m): to insert all nums into the set
//O(n): to traverse the linked list once

// SC---> O(m) ----> hashset 