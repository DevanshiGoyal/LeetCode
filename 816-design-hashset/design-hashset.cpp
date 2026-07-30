class MyHashSet {
public:
    vector<int> hash;

    MyHashSet() {

    }

    void add(int key) {
        if (!contains(key))
            hash.push_back(key);
    }

    void remove(int key) {
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] == key) {
                hash.erase(hash.begin() + i);
                return;
            }
        }
    }

    bool contains(int key) {
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] == key)
                return true;
        }
        return false;
    }
};