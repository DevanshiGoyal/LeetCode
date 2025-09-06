class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0 , count = 0 ;
        unordered_map<char , int> mp ; // To keep track of counts of 'a', 'b', and 'c'

        for(int right  = 0 ; right <s.length() ; right ++){
            mp[s[right ]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                count+= s.length() - right ; // Count substrings ending at 'right'
                // shrink from left
                mp[s[left]]--;  
                left++; 
            }

        }
        return count ;
        
    }
};