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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0) ;

        ListNode* temp = dummy ;

        int carry = 0 ;

        while(l1!=nullptr || l2 != nullptr || carry!=0){
            int digit1 , digit2 ;
            if(l1!=nullptr){
                digit1 = l1->val ;
            }else{
                digit1 = 0 ;
            }
            if(l2!=nullptr){
                digit2 = l2->val ;
            }else{
                digit2 = 0 ;
            }

            int sum = digit1 + digit2 + carry ;
            int digit = sum%10 ;
            carry = sum/10 ;

            ListNode* newNode = new ListNode(digit) ;
            temp->next = newNode ;
            temp = temp->next ;

            if(l1!=nullptr){
                l1 = l1->next ;
            }

            if(l2!=nullptr){
                l2 = l2->next ;
            }

            
        }

        return dummy->next ;
        
    }
};