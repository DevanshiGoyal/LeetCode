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
    ListNode* sortList(ListNode* head) {
        // brute force 
        if(head == NULL) return head;

        vector<int> t;

        // store values
        ListNode* temp = head;
        while(temp != NULL) {
            t.push_back(temp->val);
            temp = temp->next;
        }

        //  sort
        sort(t.begin(), t.end());

        temp = head ;
        for(int i = 0 ; i<t.size() ; i++){
            temp->val = t[i] ;
            temp = temp->next;
        }
        return head ;
    }
};