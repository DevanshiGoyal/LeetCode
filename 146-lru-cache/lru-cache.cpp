class LRUCache {
public:
    // doubly linked list node class
    class Node{
    public:
        int key ;
        int value ;
        Node* prev;
        Node* next;

        // constructor to initialise 
        Node(int k , int v){
            key = k ;
            value = v ;
        }

    };

    // head and tail dummy nodes
    Node* head = new Node(-1 , -1) ;
    Node* tail = new Node(-1 , -1) ;

    // capacity of cache 
    int cap ;
    // hashmap to store  the key and node mapping
    unordered_map<int , Node*> mp ;
    //Sc--->//  O(cap)
    
    // constructor to initialise LRU cache
    LRUCache(int capacity) {
        
        cap = capacity ;
        head->next = tail ;
        tail->prev = head ;
        
    }
    // Function to insert a node after head

    void addNode(Node* newNode){
        Node* temp = head->next ;
        newNode->next = temp ;
        newNode->prev = head ;
        head->next = newNode ;
        temp->prev = newNode ;

    }
    // Function to delete a given node 
    void removeNode(Node* delNode){
        Node *delNext = delNode->next ;
        Node* delPrev = delNode->prev;
        delPrev->next = delNext ;
        delNext->prev = delPrev;
    }
    //  O(1)
    int get(int key) {
        // if key exist 
        if(mp.find(key) != mp.end()){

            Node* resNode = mp[key];
            int resVal = resNode->value ;

            // remove old mapping  
            mp.erase(key);

            // move that node to front
            removeNode(resNode); 
            addNode(resNode);

            //update map with curr node position
            mp[key] = head->next;

            return resVal ;
        }
        // not found 
        return -1;
        
    }
    //  O(1)
    void put(int key, int value) {
        // if key already present 
        if(mp.find(key) != mp.end()){

            Node* existnode = mp[key];
            mp.erase(key);
            removeNode(existnode);

        }
        // if capacity reached 
        if(mp.size() == cap){
            mp.erase(tail->prev->key) ;
            removeNode(tail->prev) ;
        }
        // add new node to front 
        Node* newNode = new Node(key , value) ;
        addNode(newNode);
        // update map
        mp[key] = head->next ;
                
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */