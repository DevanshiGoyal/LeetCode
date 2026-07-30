class MyHashMap {
public:
    int h[1000001];

    MyHashMap() {
        memset(h, -1, sizeof(h));
    }
    
    void put(int key, int value) {
        h[key] = value;
    }
    
    int get(int key) {
        return h[key];
    }
    
    void remove(int key) {
        h[key] = -1;
    }
};
/*
Time Complexity

put → O(1)
get → O(1)
remove → O(1)
Space Complexity

O(10⁶)

*/