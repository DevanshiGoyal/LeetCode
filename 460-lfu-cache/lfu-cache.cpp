class LFUCache {
public:
    int cap ;
    int size;
    unordered_map<int , list<vector<int>>::iterator/*Address*/> mp ;  // key -> address  
    map<int , list<vector<int>>>  freq ;  // ordered map counter->{key   , value , counter}

    LFUCache(int capacity) {
        cap = capacity  ;
        size = 0 ;   
    }

    void makeMostFrequentlyUsed(int key){
        auto &vec = (*(mp[key]));

        int value = vec[1] ;
        int f = vec[2];

        freq[f].erase(mp[key]);

        if(freq[f].empty()){
            freq.erase(f) ; // empty dll
        }

        f++; // inc f 
        freq[f].push_front({key , value , f});
        mp[key] = freq[f].begin();



    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){ 
            return -1 ;} 

        auto vec = (*(mp[key])) ; // {key , value , counter} address of node (part of list)

        int value = vec[1] ;
        
        // recently used update it counter ++ 
        makeMostFrequentlyUsed(key);

        return value ;

        
    }
    
    void put(int key, int value) {
        if(cap == 0) return ;

        if(mp.find(key) != mp.end()){
            auto &vec = (*(mp[key])) ; // resolved address
            vec[1] = value;

             // recently used update it counter ++ 
            makeMostFrequentlyUsed(key);
        }

        else if(size < cap){
            size++;

            // fresh h 
            freq[1].push_front(vector<int>({key , value , 1}));
            mp[key] = freq[1].begin();

        }else{
            // no space 
            // Time to remove LFU , or LRU when there is a tie 
            auto &kaun_sa_list = freq.begin()->second;
            
            int key_delete = (kaun_sa_list.back())[0]; //ordered_map ensures that the begin() will be th eleast frequency
            
            kaun_sa_list.pop_back();
            
            if(kaun_sa_list.empty())
                freq.erase(freq.begin()->first);
            
            freq[1].push_front(vector<int>({key, value, 1}));
            
            mp.erase(key_delete);
            mp[key] = freq[1].begin();
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */