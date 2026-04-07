class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // push all heads
        for (auto node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        // Dummy node for result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();

            tail->next = top;
            tail = tail->next;

            if (top->next != nullptr) {
                pq.push(top->next);
            }
        }

        return dummy->next;
    }
};
// tc-->O(NlogK) at most k node hi aa rhe h heap m 
