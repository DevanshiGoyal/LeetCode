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

    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    //Return shortest root
    string search(string word) {
        Node* node = root;
        string prefix = "";

        for (char ch : word) {
            if (!node->containsKey(ch)) break;

            prefix += ch;
            node = node->get(ch);

            if (node->isEnd()) return prefix;
        }

        return word; // no root found
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;

        // Insert dictionary
        for (auto word : dictionary) {
            trie.addWord(word);
        }

        stringstream ss(sentence);
        string word;
        string result = "";

        while (ss >> word) {
            result += trie.search(word) + " ";
        }

        result.pop_back(); // remove trailing space
        return result;
    }
};