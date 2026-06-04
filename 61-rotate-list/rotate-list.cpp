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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==nullptr || !head->next || k==0) return head ;

        int len = 1 ;
        ListNode* tail=head;
        while(tail->next){ 
            tail=tail->next; 
            len++; 
        } 

        k = k%len ;
        if(k==0) return head ; // no rotation

        // make circular 
        tail->next = head ;

        int step = len-k ;

        ListNode* newtail=head;

        for(int i = 1 ; i<step ; i++){
            newtail = newtail->next ;
        }

        ListNode* newhead=newtail->next; 
        newtail->next=NULL; // break

        return newhead;
        
    }
};

// tc-->O(n)  sc-->O(1)