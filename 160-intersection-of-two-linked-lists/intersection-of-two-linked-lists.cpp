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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* list1 = headA;
        ListNode* list2 = headB;
        int n1 = 0, n2 = 0, it;
        while(list1 != NULL) {
            list1 = list1->next;
            n1++;
        }
        while(list2 != NULL) {
            list2 = list2->next;
            n2++;
        }
        list1 = headA;
        list2 = headB;
        if(n1 < n2) {
            it = n2 - n1;
            for(int i = 1; i <= it; i++)
                list2 = list2->next;
        }
        else {
            it = n1 - n2;
            for(int i = 1; i <= it; i++)
                list1 = list1->next;
        }

        while(list1 != NULL && list2 != NULL) {
            if(list1 == list2)
                return list1;
            list1 = list1->next;
            list2 = list2->next;
        }
        return NULL;
    }
};