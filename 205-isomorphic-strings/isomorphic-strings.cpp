class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> mp ;

        for(int i = 0 ; i<s.length() ; i++){
            char sc = s[i];
            char tc = t[i];

            if(mp.find(sc) != mp.end()){
                // check if vo previously khin kisi aur char se map toh nhi h 
                if(mp[sc]!=tc) return false ;
            }else{
                // check kisi aur se to nhi map tc aprt from sc
                for(auto &p : mp){
                    if(p.second == tc) return false ;
                }

                mp[sc] = tc ;
            }
        }

        return  true ;
        
    }
};