class Solution {
public:
    bool isAnagram(string s, string t) {
        // using hashtable
        if(s.length() != t.length()){
            return false;
        }
        int arr[26] = {0};
        for(int i=0; i<s.length(); i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(arr[i] != 0){
                return false;
            }
        }
        return true;

    }
};
/*
Tc : O(N), as we iterate the string to count the frequency of every character 
    Sc : O(1), As we are using  26 size-frequency array to store the frequency of every character which is constant
    */