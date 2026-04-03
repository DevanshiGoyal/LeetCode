// Trie Node for storing bits (0/1)

class Node {
public:
    Node* links[2];

    Node() {
        links[0] = links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};


//Trie for maximum XOR queries

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert 
    void insert(int num) {
        Node* node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    // Get maximum XOR 
    int getMax(int num) {
        Node* node = root;

        //  trie is empty
        if(!node) return -1;

        int maxXor = 0;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            //  opposite bit
            if(node->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

      
        sort(nums.begin(), nums.end());

        // {mi, xi, index}
        vector<vector<int>> Q;

        for(int i = 0; i < queries.size(); i++) {
            int xi = queries[i][0];
            int mi = queries[i][1];
            Q.push_back({mi, xi, i});
        }

        sort(Q.begin(), Q.end());

  
        vector<int> ans(queries.size(), -1);

        Trie trie;
        int i = 0; // pointer for nums

     
        for(auto &q : Q) {
            int mi = q[0];
            int xi = q[1];
            int idx = q[2];

           
            while(i < nums.size() && nums[i] <= mi) {
                trie.insert(nums[i]);
                i++;
            }

            if(i == 0) {
                ans[idx] = -1;
            } else {
                ans[idx] = trie.getMax(xi);
            }
        }

        return ans;
    }
};