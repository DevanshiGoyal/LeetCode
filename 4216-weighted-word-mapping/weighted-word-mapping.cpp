class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        unordered_map<int ,char> hash ;
        
        char c = 'z' ;
        for(int i = 0 ; i<26  ; i++){
            hash[i] = c ;
            c-- ;  
        }
        
        string ans ;
        
        for(auto &word : words){
            
            int wght = 0 ;
            
            for(char c : word){
                wght += weights[c-'a'] ;
                
            }

            ans += hash[wght % 26] ;
        }

        return ans ;
        
    }
};