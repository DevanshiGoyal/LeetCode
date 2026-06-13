class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        /*
        unordered_map<int ,char> hash ;
        
        char c = 'z' ;
        for(int i = 0 ; i<26  ; i++){
            hash[i] = c ;
            c-- ;  
        }
        */
        
        string ans ;
        
        for(auto &word : words){
            
            int wght = 0 ;
            
            for(char c : word){
                wght += weights[c-'a'] ;
                
            }

            int v = wght%26;
            ans.push_back(char('z'-v)) ;
        }

        return ans ;
        
    }
};