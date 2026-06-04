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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // brute force 
        if (head == nullptr || k <= 1) {
            return head;
        }

        int count = 0; 
        //int sizeHead = 0;
        int sizeRes = 0;

        stack<int> stk;
        ListNode* curr = head;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (curr != nullptr) {
            count++;
            //sizeHead++;
            stk.push(curr->val);
            curr = curr->next;

            if (count == k) {
                sizeRes += k;
                count = 0;
                while (!stk.empty()) {
                    tail->next = new ListNode(stk.top());
                    tail = tail->next;
                    stk.pop();
                }
            }
        }

        // Clear unused stack values (important)
        while (!stk.empty()) stk.pop();

        // Attach remaining nodes
        ListNode* temp = head;
        while (sizeRes--) {
            temp = temp->next;
        }
        tail->next = temp;

        return dummy->next;
    }

};