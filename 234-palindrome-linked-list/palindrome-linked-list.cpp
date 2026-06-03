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
 /*
//Approach-2 (Reversing the 2nd half of linked list)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revhead = reverseList(slow);
        prev->next = NULL;
        
        while(revhead != NULL && head != NULL) {
            if(revhead->val != head->val) {
                return false;
            }

            revhead = revhead->next;
            head = head->next;
        }

        return true;
    }
};

*/

//Approach-3 (Reversing the 2nd half of linked list)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;


        while(fast && fast->next) {
            fast = fast->next->next;

            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // If the number of nodes is odd, move slow to the next node
        if (fast)
            slow = slow->next;
        
        while(prev && slow) {
            if(prev->val != slow->val) {
                return false;
            }

            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};
