// Trie Node
struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    bool isEnd() {
        return flag;
    }

    void setEnd() {
        flag = true;
    }
};

// Trie Class
class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool find(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
};

class MagicDictionary {
private:
    Trie trie;  

public:
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (string s : dictionary) {
            trie.insert(s);
        }
    }

    bool search(string searchWord) {

        for (int i = 0; i < searchWord.size(); i++) {

            char original = searchWord[i];

            for (int j = 0; j < 26; j++) {

                char ch = j + 'a';
                if (ch == original) continue;

                searchWord[i] = ch;

                if (trie.find(searchWord)) {
                    return true;
                }
            }

            searchWord[i] = original; // restore
        }

        return false;
    }
};