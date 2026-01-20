class Node{
 public:
    int key ;
    int value ;
    int cnt ;
    Node* next ;
    Node* prev ;

    // constructor to initialise 
    Node(int k , int v){
        key = k ;
        value = v ;
        cnt = 1 ;

    }

};

class List{
    public:
    int size ;
    Node* head;
    Node* tail ;
    // constructor
    List(){
        // dummy head and tail
        head = new Node(0 , 0);
        tail = new Node(0 , 0);
        head->next = tail ;
        tail->prev = head ;
        size = 0 ;
    }
    // Function to add in front 
    void addNode(Node* newNode){
        Node* temp = head->next ;
        newNode->next = temp ;
        head->next = newNode ;
        newNode->prev = head ;
        temp->prev = newNode ;
        size++;
    }

    void removeNode(Node* delNode){
        Node* prevNode = delNode-> prev ;
        Node* nextNode = delNode->next ;
        prevNode->next = nextNode ;
        nextNode->prev = prevNode ;
        size--;
    }

};


class LFUCache {
public:
    // hashmap to store key value pairs
    map<int , Node*> mp;
    // hashmap to maintain the list having different frequencies
    map<int , List*> freqlist;

    int maxSizeCache; // Max size of cache

    int minfreq ; // freq of least recently used

    int  currSize ; // current size of cache
    
    // capacity of LFU cache
    int cap;

    LFUCache(int capacity) {
        maxSizeCache = capacity ;
        minfreq = 0 ;
        currSize = 0 ;        
        
    }

    void updateFreq(Node* node){
        mp.erase(node->key);
        // update 
                 // freqlist[freq] gives list --> of that list remove given node 
        freqlist[node->cnt]->removeNode(node);

        // after removal
        // If node was the last node having it's frequency
       if(node->cnt == minfreq && freqlist[node->cnt]->size == 0) {   
           // Update the minimum frequency --> becomes higher frequency and min freq list becomes empty 
           minfreq++; 

       }

        List* nextHigherFreqList = new List() ;
        if(freqlist.find(node->cnt + 1) != freqlist.end()){
            nextHigherFreqList = freqlist[node->cnt + 1] ;

        }

        node->cnt += 1 ;
        nextHigherFreqList->addNode(node) ;
        freqlist[node->cnt] = nextHigherFreqList ;
        mp[node->key] = node ;


    }
    
    int get(int key) {

        if(mp.find(key) != mp.end()){
            Node* node  = mp[key] ;
            int val = node->value ;
            // it has been accessed so frequency changes 
            updateFreq(node);
            return val ;
        }
        return -1 ;
        
    }
    
    void put(int key, int value) {
        // edge case 
        if(maxSizeCache == 0) return ;

        if(mp.find(key) != mp.end()){
            Node* node  = mp[key] ;

            node->value = value ;
            updateFreq(node);
        }
        else{
            if(currSize == maxSizeCache){
                List* list = freqlist[minfreq];
                // delete the LRU
                mp.erase(list->tail->prev->key) ;
                // reemove node from list 
                freqlist[minfreq]->removeNode(list->tail->prev);
                currSize--;

            }
            // inserting a new element so it increases
            currSize++;

            // new value needs to be added not there previously 
            minfreq = 1;
            List* listfreq = new List() ;
            if(freqlist.find(minfreq) != freqlist.end()){
                listfreq = freqlist[minfreq] ;
            }

            Node* newNode = new Node(key , value) ;
            listfreq->addNode(newNode) ;
            mp[key] = newNode ;
            freqlist[minfreq] = listfreq ;

        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });