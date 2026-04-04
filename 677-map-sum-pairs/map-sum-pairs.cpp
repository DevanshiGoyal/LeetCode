class MapSum {
private: 
    map<string , int> mp;
public:
    MapSum() {}
    
    void insert(string key, int val) {
        mp[key] = val;
        
    }
    
    int sum(string prefix) {
        int sum = 0;

        for(auto i : mp){
            if((i.first).starts_with(prefix)){ //key.starts_with(prefix)
                sum+=i.second;  // sum+=val
            }
        }

        return sum ;
//tc-->O(n*p)  sc-->O(n)
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */