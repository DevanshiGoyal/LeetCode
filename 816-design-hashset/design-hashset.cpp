class MyHashSet {
public:
//Since the constraints are 0 <= key <= 10^6, the intended solution is to use a boolean array.
    vector<bool> hash;

    MyHashSet() {
        hash.resize(1000001, false);
    }

    void add(int key) {
        hash[key] = true;
    }

    void remove(int key) {
        hash[key] = false;
    }

    bool contains(int key) {
        return hash[key];
    }
};
/*
add: O(1)
remove: O(1)
contains: O(1)
*/