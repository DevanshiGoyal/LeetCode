struct Node{

    Node* links[26] ={nullptr} ;
    bool flag = false ;

    bool containsKey( char ch){
        return links[ch - 'a'] != nullptr ;
    }

    void put(char ch , Node* node){
        links[ch-'a'] = node ;

    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }

    ~Node(){
        for(int i = 0 ; i<26 ; i++){
            if(links[i] != nullptr){
                delete links[i] ;
                links[i] = nullptr ;
            }
        }
    }

};

class WordDictionary {
    private: Node* root;
public:
    WordDictionary() {
        root = new Node() ;
        
    }
    ~WordDictionary() {
        delete root ;
        
    }
    
    void addWord(string word) {
        Node* node = root ;
        for(char ch: word){
            if(!node->containsKey(ch)){
                node->put(ch , new Node()) ;
            }
            node = node->get(ch) ;

        }
        node->setEnd() ;
        
    }
    
    bool searchUtil(Node* root,string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch=='.'){
                for(int j=0;j<26;j++){
                    if(node->links[j]!=NULL){
                        if(searchUtil(node->links[j],word.substr(i+1))){
                            return true;
                        }
                    }
                }
                return false;
            }
            if(!node->containsKey(ch)) return false;
            node=node->get(ch);
        }
        return node->isEnd();
    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */