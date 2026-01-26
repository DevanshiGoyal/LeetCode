class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st ;
        int n = num.length();
        //edge cases 
        if(k>=n) return "0" ; // each digit will be removed
        if(k==0) return num ; // no removal

        for(int i = 0 ; i< n ; i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]) ;

            // leading zeros starting zeroes like 00100
            //return 100
            if(st.size() == 1 && num[i] == '0'){
                st.pop();
            }

        }
        while(k>0 && !st.empty())
        {
            // for cases like "123456" where every num[i] > num.top() remove last k digits 
            //123 if k =3
            k--;
            st.pop();
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin() , ans.end()) ; // reverse the string

        // case 1001 k=2  "" it becomes so make it 0
        if(ans.length() == 0){
            return "0" ;
        }
        

        return ans ;
    }
};
//Tc - O(N) // as we only traversing the string for once
//Sc - O(N) // as we will store maximum of n digits in our string