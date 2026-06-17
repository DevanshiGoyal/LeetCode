//Approach-2 (Optimal)
class LRUCache {
public:
    list<int> dll; //it contains the key
    // type of address in dll list<int>::iterator
    map<int, pair<list<int>::iterator, int>> cache; //key->(list_node, value)
    int n;
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first); // delete key on that address
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!cache.count(key)) // cache.find(key) == cache.end()
            return -1;
        
        makeMostRecentlyUsed(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        } else {
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            n--;
        }
        
        if(n < 0) {
            int key_tobe_del = dll.back();
            cache.erase(key_tobe_del);

            dll.pop_back(); // purane ele at back  fresh ele at front
            n++;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */