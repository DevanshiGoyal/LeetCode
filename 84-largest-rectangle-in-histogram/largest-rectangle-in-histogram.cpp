class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size() ;
        stack<int> st ;
        
        vector<int> left(n), right(n);
        
        //NSL
        for(int i = 0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ;
                
            }
            if(st.empty()){
                left[i] = -1 ;

            }else left[i] = st.top() ;

            st.push(i) ;
        }

        while (!st.empty()) st.pop();

        //NSR

        for (int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ;
                
            }
            if(st.empty()){
                right[i] = n ;
            }else right[i] = st.top() ;

            st.push(i) ;
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;

        
    }
};

//tc-->o(n)  sc-->o(n)