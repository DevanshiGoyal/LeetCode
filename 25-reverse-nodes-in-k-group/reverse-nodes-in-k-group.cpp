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
private:
    pair<ListNode*, ListNode*> reverse(ListNode* head){
        ListNode* prev = NULL, *forward = head, *curr = head;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return {prev, head};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = head;
        ListNode* dummytemp = dummyHead;

        while(temp != NULL){
            int cnt = 1;
            ListNode* curr = temp;

            while(cnt < k && temp->next){
                cnt++;
                temp = temp->next;
            }

            if(cnt < k) break;

            ListNode* forward = temp->next;
            temp->next = NULL;

            auto res = reverse(curr);

            dummytemp->next = res.first;
            dummytemp = res.second;
            dummytemp->next = forward;

            temp = forward;
        }

        return dummyHead->next;
    }
};
//O(n)  O(1)