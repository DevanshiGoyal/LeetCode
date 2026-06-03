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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *check = head;
        int count = 0;
        while(check != nullptr){
            check = check->next;
            count++;
        }

        n = count - n + 1;
        if(n == 1)
        return head->next;

        ListNode *temp = head, *prev = nullptr;
        count = 1;
        while(head != nullptr && count != n){
            prev = head;
            head = head->next;
            count++;
        }
        prev->next = head->next;

        return temp;
    }
};