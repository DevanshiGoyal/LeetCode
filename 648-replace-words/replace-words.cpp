class Solution {
public:
// without tries using hashset
    string replaceWords(vector<string>& dictionary, string sentence) {
        // store root word 
        unordered_set<string>st(dictionary.begin() , dictionary.end()) ;

        string ans , word ;

        // process sentence 
        stringstream ss(sentence) ;
        // for each word 
        while(ss >> word){
            string str ;
            bool flag = false ;
            // search in hashset 
            for(char c : word){
                str+=c ;
                if(st.count(str)){ // if present 
                    flag = true ;
                    break ;
                }
            }
            if(flag){
                ans+=str; // replace with root word 
            }else{
                ans+=word ; // not found root so as it is word 
            }
            ans+=" " ;
        }
        if(!ans.empty()) ans.pop_back() ; // remove trailing space 
        return ans ;
        
    }
};
//tc-->O(n*m) n->length of sentence   m->avg len of word
//sc-->O(d)  d->size of dict (extra space for set storing dict words)