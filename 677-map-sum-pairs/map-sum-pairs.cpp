class node{
  public:
    node* v[26];
    int val=0;
    
    bool ispresent(char c){
        return this->v[c-'a']!=NULL;
    }
    
    void create(char c,node* n){
        this->v[c-'a']=n;
    }
    
    void addval(int value){
        this->val+=value;
    }
};

class trie{
    public:
    node* root=new node();
    
    void insert(string key,int val){
        node* r1=root;
        for(auto ele:key){
            
            if(!r1->ispresent(ele)){
                r1->create(ele,new node());    
            }
            
            r1=r1->v[ele-'a'];
            r1->addval(val);
        }
    }
    
    int countprefixsum(string prefix){
        node* r1=root;
        
        for(auto ele:prefix){
            if(!r1->ispresent(ele))return 0;
            r1=r1->v[ele-'a'];
        }
        return r1->val;
    }
};

class MapSum {
public:
    
    unordered_map<string,int>m;
    trie* root;
    MapSum() {
        root=new trie();
    }
    
    void insert(string key, int val) {
        int a=val;
        if(m.find(key)!=m.end()){
            val-=m[key];
        }    
        m[key]=a;
        root->insert(key,val);
    }
    
    int sum(string prefix) {
        return root->countprefixsum(prefix);
    }
};