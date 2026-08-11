class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> freq;

        for (int card : hand)
            freq[card]++;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> minHeap;

        for (auto &it : freq)
            minHeap.push({it.first, it.second});

        queue<pair<int, int>> pending;

        while (!minHeap.empty()) {

            int prev = -1;

            for (int cnt = 0; cnt < groupSize; cnt++) {

                if (minHeap.empty())
                    return false;

                auto [card, f] = minHeap.top();
                minHeap.pop();

                if (prev != -1 && card != prev + 1)
                    return false;

                prev = card;
                f--;

                if (f > 0)
                    pending.push({card, f});
            }

            while (!pending.empty()) {
                minHeap.push(pending.front());
                pending.pop();
            }
        }

        return true;
    }
};