/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
            return NULL;

        // Pass 1: Create copy nodes and insert them after originals
        Node* temp = head;

        while(temp != NULL) {

            Node* copy = new Node(temp->val);

            copy->next = temp->next;
            temp->next = copy;

            temp = copy->next;
        }

        // Pass 2: Assign random pointers
        temp = head;

        while(temp != NULL) {

            Node* copy = temp->next;

            if(temp->random != NULL)
                copy->random = temp->random->next;

            temp = copy->next;
        }

        // Pass 3: Separate original and copied lists
        temp = head;
        Node* newHead = head->next;

        while(temp != NULL) {

            Node* copy = temp->next;

            temp->next = copy->next;

            if(copy->next != NULL)
                copy->next = copy->next->next;

            temp = temp->next;
        }

        return newHead;
    }
};

//tc-->O(n)  sc-->O(1)