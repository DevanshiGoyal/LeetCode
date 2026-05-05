class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity
        unordered_set<string> st(wordList.begin() , wordList.end()) ;  // O(N)
        // queue ds of type {word , transition to reach word}

        if(st.find(endWord) == st.end()){
            return 0;
        }
        if(st.find(beginWord) != st.end()){
            st.erase(beginWord);
        }
        queue<pair<string , int>> q ;
        q.push({beginWord,1});

        // to mark it visited 
        st.erase(beginWord) ;
        // BFS TRAVERSAL ---. efficient  ----> O(N) ---> no . of transition 
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            // we return the steps as soon as
            // the first occurence of targetWord is found.
            if(word==endWord) return steps;

            //O(word.length * 26)
            for(int i = 0 ; i<word.size() ; i++){
                char original = word[i] ;

                for(char ch = 'a' ; ch<='z' ; ch++){
                    word[i] = ch ;
                    // check if it exists in the set and push it in the queue
                    if(st.find(word) != st.end()){
                        st.erase(word) ;
                        q.push({word , steps + 1 }) ;
                    }
                } 
                word[i] = original ;
            }
        }
        // If there is no transformation sequence possible
        return 0;
        
    }
};

// TC---> O(N* word.length * 26 * )
// SC:  O( N ) { for creating an unordered set and copying all values from wordList into it }

// N = size of wordList Array.