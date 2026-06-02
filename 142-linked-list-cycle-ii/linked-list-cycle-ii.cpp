/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Pointer's intialize at head of linkedlist
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){ // running the loop until 
            slow = slow->next; // moving slow by 1
            fast = fast->next->next; // moving fast by 2
            if(slow == fast){ // if they meet
                slow = head; // reset slow to head
                while(slow != fast){ // run loop until again fast & slow don't collab
                    slow = slow->next; // moving slow by 1
                    fast = fast->next; // moving fast by 1 as well
                }
                return slow; // Or return fast same thing, they will return the tail where cycle starts
            }
        }
        return nullptr; // if there is no cycle, it will return null
       }
};