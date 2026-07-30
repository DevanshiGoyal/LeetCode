class Solution {
public:
    // optimal approachh 
    string encode(string& s){
        vector<int> freq(26 , 0);
        for(auto& ch : s){
            freq[ch-'a']++;
        }
        string encoded = "";
        for(int i = 0 ; i<26 ; i++){
            encoded+=char('a' + i) + to_string(freq[i]);
        }
        return encoded ;
    }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& s : strs)
            mp[encode(s)].push_back(s);
        vector<vector<string>> ans;
        for (auto& [key, vec] : mp)
            ans.push_back(vec);
        return ans;
    
               
    }
};
//O(n × k)	      sc --- O(n × k)

/*

Dry Run
Input: ["eat", "tea", "tan", "ate", "nat", "bat"]

String	Encoded Key	Group
"eat"	a1...e1...t1...	Group A
"tea"	a1...e1...t1...	Group A
"tan"	a1...n1...t1...	Group B
"ate"	a1...e1...t1...	Group A
"nat"	a1...n1...t1...	Group B
"bat"	a1...b1...t1...	Group C
Output: [["eat","tea","ate"], ["tan","nat"], ["bat"]]
*/